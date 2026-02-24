using System;
using System.Text.Json;

class S043 {
  record Req(string Action, int[] Args);
  static void Main(string[] args) {
    var req = JsonSerializer.Deserialize<Req>(args.Length>0?args[0]:"{\"Action\":\"sum\",\"Args\":[1,2,3]}");
    if (req is null) return;
    if (req.Action == "sum") {
      int s=0; foreach (var x in req.Args) s+=x;
      Console.WriteLine(s);
    } else Console.WriteLine("not allowed");
  }
}