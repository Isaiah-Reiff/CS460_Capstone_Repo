// VULN: evaluates user-controlled C# script
using System;
using System.Threading.Tasks;
using Microsoft.CodeAnalysis.CSharp.Scripting;

class V044 {
  static async Task Main(string[] args) {
    var src = args.Length > 0 ? args[0] : "1+2";
    Console.WriteLine(await CSharpScript.EvaluateAsync<object>(src)); // CWE-94
  }
}