using System;
using System.Collections.Generic;
using System.Threading.Tasks;

public class SafeRunner
{
    private readonly Dictionary<string, Func<int, int, int>> AllowedOps =
        new Dictionary<string, Func<int, int, int>>(StringComparer.OrdinalIgnoreCase)
        {
            { "add", (a, b) => a + b },
            { "sub", (a, b) => a - b },
            { "mul", (a, b) => a * b },
            { "div", (a, b) => b != 0 ? a / b : throw new DivideByZeroException() }
        };

    public Task<string> Execute(string op, int a, int b)
    {
        if (!AllowedOps.ContainsKey(op))
            return Task.FromResult("Invalid operation");

        int result = AllowedOps[op](a, b);
        return Task.FromResult($"Result: {result}");
    }
}
