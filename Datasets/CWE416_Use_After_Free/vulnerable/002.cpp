#include "std_testcase.h"
#include <wchar.h>
namespace ModuleX__new_delete_class_02
{
#ifndef FLAG_A
void execute_a() {
    TwoIntsClass * data;
    data = NULL;
    if(1)
    {
        data = new TwoIntsClass;
        data->intOne = 1;
        data->intTwo = 2;
        delete data;
    }
    if(1)
    {
        printIntLine(data->intOne);
    }
}
#endif 
#ifndef FLAG_B
static void variant_a1()
{
    TwoIntsClass * data;
    data = NULL;
    if(1)
    {
        data = new TwoIntsClass;
        data->intOne = 1;
        data->intTwo = 2;
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
    TwoIntsClass * data;
    data = NULL;
    if(1)
    {
        data = new TwoIntsClass;
        data->intOne = 1;
        data->intTwo = 2;
        delete data;
    }
    if(1)
    {
        ; 
    }
}
static void variant_b1()
{
    TwoIntsClass * data;
    data = NULL;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = new TwoIntsClass;
        data->intOne = 1;
        data->intTwo = 2;
    }
    if(1)
    {
        printIntLine(data->intOne);
    }
}
static void variant_b2()
{
    TwoIntsClass * data;
    data = NULL;
    if(1)
    {
        data = new TwoIntsClass;
        data->intOne = 1;
        data->intTwo = 2;
    }
    if(1)
    {
        printIntLine(data->intOne);
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
using namespace ModuleX_new_delete_class_02; 
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

