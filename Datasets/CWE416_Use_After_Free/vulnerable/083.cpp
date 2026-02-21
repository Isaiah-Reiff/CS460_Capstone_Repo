#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__malloc_free_int_43
{
#ifndef FLAG_A
static void source_a(int * &data)
{
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
}
void execute_a()
{
    int * data;
    data = NULL;
    source_a(data);
    printIntLine(data[0]);
}
#endif 
#ifndef FLAG_B
static void source_b1(int * &data)
{
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5;
        }
    }
}
static void variant_b()
{
    int * data;
    data = NULL;
    source_b1(data);
    printIntLine(data[0]);
}
static void source_b2(int * &data)
{
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
}
static void variant_a()
{
    int * data;
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
using namespace ModuleX_malloc_free_int_43; 
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

