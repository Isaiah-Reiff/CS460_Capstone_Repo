#include "std_testcase.h"
#include <wchar.h>
#ifndef FLAG_A
void ModuleX__malloc_free_int_01_execute_a()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
    free(data);
    printIntLine(data[0]);
}
#endif 
#ifndef FLAG_B
static void variant_b()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
    printIntLine(data[0]);
}
static void variant_a()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
    free(data);
    ; 
}
void ModuleX__malloc_free_int_01_execute_b()
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
    ModuleX__malloc_free_int_01_execute_b();
    printLine("Finished execute_b()");
#endif 
#ifndef FLAG_A
    printLine("Calling execute_a()...");
    ModuleX__malloc_free_int_01_execute_a();
    printLine("Finished execute_a()");
#endif 
    return 0;
}
#endif

