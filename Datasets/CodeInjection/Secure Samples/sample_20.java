import javax.servlet.http.*;
import java.io.IOException;
import java.util.Map;
import java.util.HashMap;

public class SafeController extends HttpServlet {

    @FunctionalInterface
    interface Action {
        String apply(String input);
    }

    private static final Map<String, Action> allowed = new HashMap<>();

    static {
        allowed.put("reverse", s -> new StringBuilder(s).reverse().toString());
        allowed.put("upper",   String::toUpperCase);
        allowed.put("lower",   String::toLowerCase);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String action = req.getParameter("action");
        String value  = req.getParameter("value");

        if (!allowed.containsKey(action)) {
            resp.setStatus(400);
            resp.getWriter().write("Invalid action");
            return;
        }

        String result = allowed.get(action).apply(value);
        resp.getWriter().write(result);
    }
}
