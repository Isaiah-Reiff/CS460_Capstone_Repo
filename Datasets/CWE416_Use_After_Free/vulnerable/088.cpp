#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__new_delete_int_43
{
#ifndef FLAG_A
void source_a(int * &data)
{
    data = new int;
    *data = 5;
    delete data;
}
void execute_a()
{
    int * data;
    data = NULL;
    source_a(data);
    printIntLine(*data);
}
#endif 
#ifndef FLAG_B
static void source_b1(int * &data)
{
    data = new int;
    *data = 5;
}
static void variant_b()
{
    int * data;
    data = NULL;
    source_b1(data);
    printIntLine(*data);
}
static void source_b2(int * &data)
{
    data = new int;
    *data = 5;
    delete data;
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
using namespace ModuleX_new_delete_int_43; 
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

