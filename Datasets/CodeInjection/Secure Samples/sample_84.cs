using System;
using System.Collections.Generic;

class S042 {
  static void Main(string[] args) {
    var ops = new Dictionary<string, Func<int,int,int>> {
      ["add"] = (a,b)=>a+b, ["mul"]=(a,b)=>a*b
    };
    var op = args.Length>0?args[0]:"add";
    int a = args.Length>1?int.Parse(args[1]):2;
    int b = args.Length>2?int.Parse(args[2]):3;
    Console.WriteLine(ops.ContainsKey(op) ? ops[op](a,b) : -1);
  }
}