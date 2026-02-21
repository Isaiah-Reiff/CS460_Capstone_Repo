#include "std_testcase.h"
#include <wchar.h>
#ifndef FLAG_A
void ModuleX__malloc_free_char_01_execute_a()
{
    char * data;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    free(data);
    printLine(data);
}
#endif 
#ifndef FLAG_B
static void variant_b()
{
    char * data;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    printLine(data);
}
static void variant_a()
{
    char * data;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    free(data);
    ; 
}
void ModuleX__malloc_free_char_01_execute_b()
{
    variant_b();
    variant_a();
}
#endif 
#ifdef INCLUDEMAIN
int main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
#ifndef FLAG_B
    printLine("Calling execute_b()...");
    ModuleX__malloc_free_char_01_execute_b();
    printLine("Finished execute_b()");
#endif 
#ifndef FLAG_A
    printLine("Calling execute_a()...");
    ModuleX__malloc_free_char_01_execute_a();
    printLine("Finished execute_a()");
#endif 
    return 0;
}
#endif

