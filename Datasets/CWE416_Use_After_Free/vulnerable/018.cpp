#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__malloc_free_char_43
{
#ifndef FLAG_A
static void source_a(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    free(data);
}
void execute_a()
{
    char * data;
    data = NULL;
    source_a(data);
    printLine(data);
}
#endif 
#ifndef FLAG_B
static void source_b1(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
}
static void variant_b()
{
    char * data;
    data = NULL;
    source_b1(data);
    printLine(data);
}
static void source_b2(char * &data)
{
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    free(data);
}
static void variant_a()
{
    char * data;
    data = NULL;
    source_b2(data);
    ; 
}
void execute_b()
{
    variant_b();
    variant_a();
}
#endif 
} 
#ifdef INCLUDEMAIN
using namespace ModuleX_malloc_free_char_43; 
int main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
#ifndef FLAG_B
    printLine("Calling execute_b()...");
    execute_b();
    printLine("Finished execute_b()");
#endif 
#ifndef FLAG_A
    printLine("Calling execute_a()...");
    execute_a();
    printLine("Finished execute_a()");
#endif 
    return 0;
}
#endif

