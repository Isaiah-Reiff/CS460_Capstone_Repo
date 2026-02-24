#include "std_testcase.h"
static char * helper_a(char * aString)
{
    size_t i = 0;
    size_t j;
    char * reversedString = NULL;
    if (aString != NULL)
    {
        i = strlen(aString);
        reversedString = (char *) malloc(i+1);
        if (reversedString == NULL) {exit(-1);}
        for (j = 0; j < i; j++)
        {
            reversedString[j] = aString[i-j-1];
        }
        reversedString[i] = '\0';
        free(reversedString);
        return reversedString;
    }
    else
    {
        return NULL;
    }
}
static char * helper_b(char * aString)
{
    size_t i = 0;
    size_t j;
    char * reversedString = NULL;
    if (aString != NULL)
    {
        i = strlen(aString);
        reversedString = (char *) malloc(i+1);
        if (reversedString == NULL) {exit(-1);}
        for (j = 0; j < i; j++)
        {
            reversedString[j] = aString[i-j-1];
        }
        reversedString[i] = '\0';
        return reversedString;
    }
    else
    {
        return NULL;
    }
}
#ifndef FLAG_A
void ModuleX__return_freed_ptr_02_execute_a()
{
    if(1)
    {
        {
            char * reversedString = helper_a("BadSink");
            printLine(reversedString);
        }
    }
}
#endif 
#ifndef FLAG_B
static void variant_c1()
{
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * reversedString = helper_b("GoodSink");
            printLine(reversedString);
        }
    }
}
static void variant_c2()
{
    if(1)
    {
        {
            char * reversedString = helper_b("GoodSink");
            printLine(reversedString);
        }
    }
}
void ModuleX__return_freed_ptr_02_execute_b()
{
    variant_c1();
    variant_c2();
}
#endif 
#ifdef INCLUDEMAIN
int main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
#ifndef FLAG_B
    printLine("Calling execute_b()...");
    ModuleX__return_freed_ptr_02_execute_b();
    printLine("Finished execute_b()");
#endif 
#ifndef FLAG_A
    printLine("Calling execute_a()...");
    ModuleX__return_freed_ptr_02_execute_a();
    printLine("Finished execute_a()");
#endif 
    return 0;
}
#endif

