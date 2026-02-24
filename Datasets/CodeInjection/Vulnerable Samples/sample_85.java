import javax.script.*;
public class V043 {
  public static void main(String[] args) throws Exception {
    String frag = args.length > 0 ? args[0] : "1+2";
    String script = "var x = " + frag + "; x;";
    ScriptEngine e = new ScriptEngineManager().getEngineByName("JavaScript");
    System.out.println(e.eval(script));
  }
}