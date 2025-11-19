using System;
using System.Collections.Generic;

public class SafeMath
{
    private static readonly HashSet<string> AllowedOps =
        new HashSet<string>(StringComparer.OrdinalIgnoreCase)
        {
            "add", "sub", "mul", "div"
        };

    public string Evaluate(string operation, string aStr, string bStr)
    {
        if (!AllowedOps.Contains(operation))
            return "Invalid operation";

        if (!int.TryParse(aStr, out int a) ||
            !int.TryParse(bStr, out int b))
            return "Invalid numbers";

        return operation.ToLower() switch
        {
            "add" => (a + b).ToString(),
            "sub" => (a - b).ToString(),
            "mul" => (a * b).ToString(),
            "div" => b != 0 ? (a / b).ToString() : "Divide by zero",
            _ => "Invalid op"
        };
    }
}
