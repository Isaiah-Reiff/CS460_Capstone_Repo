import javax.servlet.http.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class SafeServlet extends HttpServlet {

    interface Operation {
        String run(String input);
    }

    private static final Map<String, Operation> ops = new HashMap<>();

    static {
        ops.put("reverse", s -> new StringBuilder(s).reverse().toString());
        ops.put("lower",   String::toLowerCase);
        ops.put("upper",   String::toUpperCase);
        ops.put("length",  s -> String.valueOf(s.length()));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String op = req.getParameter("op");
        String val = req.getParameter("value");

        if (!ops.containsKey(op)) {
            resp.setStatus(400);
            resp.getWriter().write("Invalid operation");
            return;
        }

        String result = ops.get(op).run(val);
        resp.getWriter().write(result);
    }
}