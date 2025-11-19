using System;
using System.Collections.Generic;
using System.Web;

public class SecureHandler : IHttpHandler
{
    private static readonly HashSet<string> AllowedCommands = new HashSet<string>
    {
        "ADD",
        "SUB",
        "MUL",
        "DIV"
    };

    public void ProcessRequest(HttpContext context)
    {
        string cmd = context.Request.Form["command"];
        string aStr = context.Request.Form["a"];
        string bStr = context.Request.Form["b"];

        if (!AllowedCommands.Contains(cmd))
        {
            context.Response.Write("Invalid command.");
            return;
        }

        if (!double.TryParse(aStr, out double a) ||
            !double.TryParse(bStr, out double b))
        {
            context.Response.Write("Invalid numeric input.");
            return;
        }

        double result;

        switch (cmd)
        {
            case "ADD": result = a + b; break;
            case "SUB": result = a - b; break;
            case "MUL": result = a * b; break;
            case "DIV":
                if (b == 0)
                {
                    context.Response.Write("Division by zero.");
                    return;
                }
                result = a / b;
                break;
            default:
                context.Response.Write("Unexpected command.");
                return;
        }

        context.Response.Write($"Result: {result}");
    }

    public bool IsReusable => false;
}
