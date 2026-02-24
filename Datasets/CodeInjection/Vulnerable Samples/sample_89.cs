// VULN: executes user-controlled JS in embedded engine
using System;
using Microsoft.ClearScript.V8;

class V045 {
  static void Main(string[] args) {
    var code = args.Length > 0 ? args[0] : "1+2";
    using var e = new V8ScriptEngine();
    Console.WriteLine(e.Evaluate(code)); // CWE-94
  }
}