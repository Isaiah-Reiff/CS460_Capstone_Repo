#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__new_delete_int64_t_01
{
#ifndef FLAG_A
void execute_a() {
    int64_t * data;
    data = NULL;
    data = new int64_t;
    *data = 5LL;
    delete data;
    printLongLongLine(*data);
}
#endif 
#ifndef FLAG_B
static void variant_b()
{
    int64_t * data;
    data = NULL;
    data = new int64_t;
    *data = 5LL;
    printLongLongLine(*data);
}
static void variant_a()
{
    int64_t * data;
    data = NULL;
    data = new int64_t;
    *data = 5LL;
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
using namespace ModuleX_new_delete_int64_t_01; 
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

