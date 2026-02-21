#include "std_testcase.h"
#include <wchar.h>
#ifndef FLAG_A
void ModuleX__malloc_free_char_02_execute_a()
{
    char * data;
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        free(data);
    }
    if(1)
    {
        printLine(data);
    }
}
#endif 
#ifndef FLAG_B
static void variant_a1()
{
    char * data;
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        free(data);
    }
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        ; 
    }
}
static void variant_a2()
{
    char * data;
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
        free(data);
    }
    if(1)
    {
        ; 
    }
}
static void variant_b1()
{
    char * data;
    data = NULL;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
    }
    if(1)
    {
        printLine(data);
    }
}
static void variant_b2()
{
    char * data;
    data = NULL;
    if(1)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
    }
    if(1)
    {
        printLine(data);
    }
}
void ModuleX__malloc_free_char_02_execute_b()
{
    variant_a1();
    variant_a2();
    variant_b1();
    variant_b2();
}
#endif 
#ifdef INCLUDEMAIN
int main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
#ifndef FLAG_B
    printLine("Calling execute_b()...");
    ModuleX__malloc_free_char_02_execute_b();
    printLine("Finished execute_b()");
#endif 
#ifndef FLAG_A
    printLine("Calling execute_a()...");
    ModuleX__malloc_free_char_02_execute_a();
    printLine("Finished execute_a()");
#endif 
    return 0;
}
#endif

