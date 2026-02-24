using System;
using System.Reflection;
using System.Linq.Expressions;

public class Executor
{
    public void Run(string userExpression)
    {
        // Vulnerable: user-provided C# expression is compiled into a delegate
        var lambda = System.Linq.Dynamic.Core.DynamicExpressionParser.ParseLambda(
            null, 
            typeof(int), 
            userExpression
        );

        int result = (int)lambda.Compile().DynamicInvoke();
        Console.WriteLine("Result: " + result);
    }
}
