import javax.servlet.http.*;
import javax.script.*;

public class VulnerableController extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) {
        try {
            String js = req.getParameter("js");  // attacker‑controlled script

            ScriptEngine engine = new ScriptEngineManager().getEngineByName("JavaScript");

            // Directly evaluates attacker-controlled JavaScript inside the JVM
            Object result = engine.eval(js);

            resp.getWriter().write("Result: " + String.valueOf(result));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}