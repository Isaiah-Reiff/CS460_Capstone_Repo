using System;
using System.CodeDom.Compiler;
using Microsoft.CSharp;

public class DynamicRunner
{
    public string Run(string userCode)
    {
        var provider = new CSharpCodeProvider();
        var cp = new CompilerParameters
        {
            GenerateInMemory = true
        };

        var results = provider.CompileAssemblyFromSource(cp, userCode);

        if (results.Errors.HasErrors)
            return "Compilation failed";

        var asm = results.CompiledAssembly;
        var t = asm.GetType("UserProgram");
        var m = t.GetMethod("Execute");
        return (string)m.Invoke(null, null);
    }
}
