#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__new_delete_long_01
{
#ifndef FLAG_A
void execute_a()
{
    long * data;
    data = NULL;
    data = new long;
    *data = 5L;
    delete data;
    printLongLine(*data);
}
#endif 
#ifndef FLAG_B
static void variant_b()
{
    long * data;
    data = NULL;
    data = new long;
    *data = 5L;
    printLongLine(*data);
}
static void variant_a()
{
    long * data;
    data = NULL;
    data = new long;
    *data = 5L;
    delete data;
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
using namespace ModuleX_new_delete_long_01; 
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

