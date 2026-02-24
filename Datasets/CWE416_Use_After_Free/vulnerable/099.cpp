#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__new_delete_int64_t_02
{
#ifndef FLAG_A
void execute_a()
{
    int64_t * data;
    data = NULL;
    if(1)
    {
        data = new int64_t;
        *data = 5LL;
        delete data;
    }
    if(1)
    {
        printLongLongLine(*data);
    }
}
#endif 
#ifndef FLAG_B
static void variant_a1()
{
    int64_t * data;
    data = NULL;
    if(1)
    {
        data = new int64_t;
        *data = 5LL;
        delete data;
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
    int64_t * data;
    data = NULL;
    if(1)
    {
        data = new int64_t;
        *data = 5LL;
        delete data;
    }
    if(1)
    {
        ; 
    }
}
static void variant_b1()
{
    int64_t * data;
    data = NULL;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = new int64_t;
        *data = 5LL;
    }
    if(1)
    {
        printLongLongLine(*data);
    }
}
static void variant_b2()
{
    int64_t * data;
    data = NULL;
    if(1)
    {
        data = new int64_t;
        *data = 5LL;
    }
    if(1)
    {
        printLongLongLine(*data);
    }
}
void execute_b()
{
    variant_a1();
    variant_a2();
    variant_b1();
    variant_b2();
}
#endif 
} 
#ifdef INCLUDEMAIN
using namespace ModuleX_new_delete_int64_t_02; 
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

