// VULN: compiles user-provided source
using System;
using Microsoft.CSharp;
using System.CodeDom.Compiler;

class V046 {
  static void Main(string[] args) {
    string src = args.Length > 0 ? args[0] : "public class X{ public static int Go(){ return 1; } }";
    var prov = new CSharpCodeProvider();
    prov.CompileAssemblyFromSource(new CompilerParameters(), src); // CWE-94
    Console.WriteLine("compiled");
  }
}