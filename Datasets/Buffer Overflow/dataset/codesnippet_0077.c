

#include "avcodec.h"
#include "ass.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"

static int ass_subtitle_header(AVCodecContext *avctx,
                               const char *font, int font_size,
                               int color, int back_color,
                               int bold, int italic, int underline,
                               int alignment)
{
    char header[512];

    snprintf(header, sizeof(header),
             "[Script Info]\r\n"
             "ScriptType: v4.00+\r\n"
             "\r\n"
             "[V4+ Styles]\r\n"
             "Format: Name, Fontname, Fontsize, PrimaryColour, SecondaryColour, OutlineColour, BackColour, Bold, Italic, Underline, BorderStyle, Outline, Shadow, Alignment, MarginL, MarginR, MarginV, AlphaLevel, Encoding\r\n"
             "Style: Default,%s,%d,&H%x,&H%x,&H%x,&H%x,%d,%d,%d,1,1,0,%d,10,10,10,0,0\r\n"
             "\r\n"
             "[Events]\r\n"
             "Format: Layer, Start, End, Text\r\n",
             font, font_size, color, color, back_color, back_color,
             -bold, -italic, -underline, alignment);

    avctx->subtitle_header = av_strdup(header);
    if (!avctx->subtitle_header)
        return AVERROR(ENOMEM);
    avctx->subtitle_header_size = strlen(avctx->subtitle_header);
    return 0;
}

int ff_ass_subtitle_header_default(AVCodecContext *avctx)
{
    return ass_subtitle_header(avctx, ASS_DEFAULT_FONT,
                               ASS_DEFAULT_FONT_SIZE,
                               ASS_DEFAULT_COLOR,
                               ASS_DEFAULT_BACK_COLOR,
                               ASS_DEFAULT_BOLD,
                               ASS_DEFAULT_ITALIC,
                               ASS_DEFAULT_UNDERLINE,
                               ASS_DEFAULT_ALIGNMENT);
}

void ff_ass_init(AVSubtitle *sub)
{
    memset(sub, 0, sizeof(*sub));
}

static int ts_to_string(char *str, int strlen, int ts)
{
    int h, m, s;
    h = ts/360000;  ts -= 360000*h;
    m = ts/  6000;  ts -=   6000*m;
    s = ts/   100;  ts -=    100*s;
    return snprintf(str, strlen, "%d:%02d:%02d.%02d", h, m, s, ts);
}

int ff_ass_add_rect(AVSubtitle *sub, const char *dialog,
                    int ts_start, int ts_end, int raw)
{
    int len = 0, dlen, duration = ts_end - ts_start;
    char s_start[16], s_end[16], header[48] = {0};
    AVSubtitleRect **rects;

    if (!raw) {
        ts_to_string(s_start, sizeof(s_start), ts_start);
        ts_to_string(s_end,   sizeof(s_end),   ts_end  );
        len = snprintf(header, sizeof(header), "Dialogue: 0,%s,%s,",
                       s_start, s_end);
    }

    dlen = strcspn(dialog, "\n");
    dlen += dialog[dlen] == '\n';

    rects = av_realloc(sub->rects, (sub->num_rects+1) * sizeof(*sub->rects));
    if (!rects)
        return AVERROR(ENOMEM);
    sub->rects = rects;
    sub->end_display_time = FFMAX(sub->end_display_time, 10 * duration);
    rects[sub->num_rects]       = av_mallocz(sizeof(*rects[0]));
    rects[sub->num_rects]->type = SUBTITLE_ASS;
    rects[sub->num_rects]->ass  = av_malloc(len + dlen + 1);
    strcpy (rects[sub->num_rects]->ass      , header);
    av_strlcpy(rects[sub->num_rects]->ass + len, dialog, dlen + 1);
    sub->num_rects++;
    return dlen;
}

