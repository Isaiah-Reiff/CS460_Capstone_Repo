#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__new_delete_array_int64_t_43
{
#ifndef FLAG_A
void source_a(int64_t * &data)
{
    data = new int64_t[100];
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5LL;
        }
    }
    delete [] data;
}
void execute_a() {
    int64_t * data;
    data = NULL;
    source_a(data);
    printLongLongLine(data[0]);
}
#endif 
#ifndef FLAG_B
static void source_b1(int64_t * &data)
{
    data = new int64_t[100];
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5LL;
        }
    }
}
static void variant_b()
{
    int64_t * data;
    data = NULL;
    source_b1(data);
    printLongLongLine(data[0]);
}
static void source_b2(int64_t * &data)
{
    data = new int64_t[100];
    {
        size_t i;
        for(i = 0; i < 100; i++)
        {
            data[i] = 5LL;
        }
    }
    delete [] data;
}
static void variant_a()
{
    int64_t * data;
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
using namespace ModuleX_new_delete_array_int64_t_43; 
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

