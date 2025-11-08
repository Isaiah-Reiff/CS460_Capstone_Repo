using System;
using System.Collections.Generic;
class App {
  static Dictionary<string, Func<int,int,int>> cmds = new(){
    {"add",(a,b)=>a+b}
  };
  static void Main(){
    var res = cmds["add"](2,3);
    Console.WriteLine(res);
  }
}
