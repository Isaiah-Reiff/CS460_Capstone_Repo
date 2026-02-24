import javax.servlet.http.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class SafeHandler extends HttpServlet {

    interface Command {
        String apply(String arg);
    }

    private static final Map<String, Command> commands = new HashMap<>();

    static {
        commands.put("reverse", s -> new StringBuilder(s).reverse().toString());
        commands.put("trim",    s -> s.trim());
        commands.put("upper",   s -> s.toUpperCase());
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws IOException {

        String cmdName = req.getParameter("cmd");
        String value   = req.getParameter("value");

        if (!commands.containsKey(cmdName)) {
            resp.setStatus(400);
            resp.getWriter().write("Invalid command");
            return;
        }

        String result = commands.get(cmdName).apply(value);
        resp.getWriter().write(result);
    }
}