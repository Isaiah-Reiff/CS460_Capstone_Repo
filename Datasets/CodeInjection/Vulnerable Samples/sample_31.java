import javax.script.*;
ScriptEngine engine = new ScriptEngineManager().getEngineByName("nashorn");
String script = request.getParameter("script");
engine.eval(script);