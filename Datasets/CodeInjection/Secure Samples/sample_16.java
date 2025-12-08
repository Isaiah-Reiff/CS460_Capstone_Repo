import java.util.HashMap;
import java.util.Map;
import javax.servlet.http.*;

public class SafeController extends HttpServlet {

    @FunctionalInterface
    interface Action {
        String run(String arg);
    }

    private static final Map<String, Action> actions = new HashMap<>();

    static {
        actions.put("upper",  s -> s.toUpperCase());
        actions.put("lower",  s -> s.toLowerCase());
        actions.put("length", s -> String.valueOf(s.length()));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) {
        String action = req.getParameter("action");
        String input  = req.getParameter("value");

        if (!actions.containsKey(action)) {
            resp.setStatus(400);
            write(resp, "Invalid action");
            return;
        }

        String result = actions.get(action).run(input);
        write(resp, result);
    }

    private void write(HttpServletResponse resp, String msg) {
        try {
            resp.getWriter().write(msg);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}