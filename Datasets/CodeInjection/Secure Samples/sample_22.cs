using System;
using System.Collections.Generic;
using System.Web;

public class JsRequestHandler : IHttpHandler
{
    private static readonly Dictionary<string, Func<int, int, int>> AllowedOps =
        new Dictionary<string, Func<int, int, int>>(StringComparer.OrdinalIgnoreCase)
        {
            { "add", (a, b) => a + b },
            { "sub", (a, b) => a - b },
            { "mul", (a, b) => a * b },
            { "div", (a, b) => b != 0 ? a / b : throw new DivideByZeroException() }
        };

    public void ProcessRequest(HttpContext context)
    {
        string op = context.Request["op"];
        string aStr = context.Request["a"];
        string bStr = context.Request["b"];

        if (!AllowedOps.ContainsKey(op))
        {
            context.Response.Write("Invalid operation.");
            return;
        }

        if (!int.TryParse(aStr, out var a) || !int.TryParse(bStr, out var b))
        {
            context.Response.Write("Invalid numeric input.");
            return;
        }

        int result = AllowedOps[op](a, b);
        context.Response.Write("Result: " + result);
    }

    public bool IsReusable => false;
}
