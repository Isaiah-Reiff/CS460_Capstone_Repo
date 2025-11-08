import javax.script.*;
public class Guarded {
  public static void main(String[] a) throws Exception {
    ScriptEngineManager mgr = new ScriptEngineManager();
    ScriptEngine engine = mgr.getEngineByName("nashorn");
    engine.eval("var x = 1+2; x;");
  }
}
