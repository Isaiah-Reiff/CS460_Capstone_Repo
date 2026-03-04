import javax.script.*;
public class V041 {
  public static void main(String[] args) throws Exception {
    String s = args.length > 0 ? args[0] : "1+2";
    ScriptEngine e = new ScriptEngineManager().getEngineByName("JavaScript");
    System.out.println(e.eval(s));
  }
}