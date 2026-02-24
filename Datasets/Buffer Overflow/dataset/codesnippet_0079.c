

#include "libcap.h"

cap_t cap_init(void)
{
    __u32 *raw_data;
    cap_t result;

    raw_data = malloc( sizeof(__u32) + sizeof(*result) );

    if (raw_data == NULL) {
	_cap_debug("out of memory");
	errno = ENOMEM;
	return NULL;
    }

    *raw_data = CAP_T_MAGIC;
    result = (cap_t) (raw_data + 1);
    memset(result, 0, sizeof(*result));

    result->head.version = _LIBCAP_CAPABILITY_VERSION;
    capget(&result->head, NULL);      

    switch (result->head.version) {
#ifdef _LINUX_CAPABILITY_VERSION_1
    case _LINUX_CAPABILITY_VERSION_1:
	break;
#endif
#ifdef _LINUX_CAPABILITY_VERSION_2
    case _LINUX_CAPABILITY_VERSION_2:
	break;
#endif
#ifdef _LINUX_CAPABILITY_VERSION_3
    case _LINUX_CAPABILITY_VERSION_3:
	break;
#endif
    default:                          
	cap_free(result);
	result = NULL;
	break;
    }

    return result;
}

char *_libcap_strdup(const char *old)
{
    __u32 *raw_data;

    if (old == NULL) {
	errno = EINVAL;
	return NULL;
    }

    raw_data = malloc( sizeof(__u32) + strlen(old) + 1 );
    if (raw_data == NULL) {
	errno = ENOMEM;
	return NULL;
    }

    *(raw_data++) = CAP_S_MAGIC;
    strcpy((char *) raw_data, old);

    return ((char *) raw_data);
}

cap_t cap_dup(cap_t cap_d)
{
    cap_t result;

    if (!good_cap_t(cap_d)) {
	_cap_debug("bad argument");
	errno = EINVAL;
	return NULL;
    }

    result = cap_init();
    if (result == NULL) {
	_cap_debug("out of memory");
	return NULL;
    }

    memcpy(result, cap_d, sizeof(*cap_d));

    return result;
}

int cap_free(void *data_p)
{
    if ( !data_p )
	return 0;

    if ( good_cap_t(data_p) ) {
	data_p = -1 + (__u32 *) data_p;
	memset(data_p, 0, sizeof(__u32) + sizeof(struct _cap_struct));
	free(data_p);
	data_p = NULL;
	return 0;
    }

    if ( good_cap_string(data_p) ) {
	size_t length = strlen(data_p) + sizeof(__u32);
     	data_p = -1 + (__u32 *) data_p;
     	memset(data_p, 0, length);
     	free(data_p);
     	data_p = NULL;
     	return 0;
    }

    _cap_debug("don't recognize what we're supposed to liberate");
    errno = EINVAL;
    return -1;
}

