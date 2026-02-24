using System;
using System.Collections.Generic;

public class SafeExecutor
{
    private readonly Dictionary<string, Func<int, int, int>> Allowed =
        new Dictionary<string, Func<int, int, int>>(StringComparer.OrdinalIgnoreCase)
        {
            { "add", (a, b) => a + b },
            { "multiply", (a, b) => a * b }
        };

    public string Execute(string action, string aStr, string bStr)
    {
        if (!Allowed.ContainsKey(action))
            return "Invalid action";

        if (!int.TryParse(aStr, out int a) ||
            !int.TryParse(bStr, out int b))
            return "Invalid numeric input";

        int result = Allowed[action](a, b);
        return $"Result: {result}";
    }
}
