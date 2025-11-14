import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class XSSFixedServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String userInput = request.getParameter("input");

        
        String safeUserInput = sanitizeUserInput(userInput);

        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<body>");
        out.println("<h1>Hello, " + safeUserInput + "!</h1>");
        out.println("</body>");
        out.println("</html>");
    }

    private String sanitizeUserInput(String userInput) {
        
        
        
        
        return userInput != null ? userInput.replaceAll("<", "&lt;").replaceAll(">", "&gt;")
                                    .replaceAll("&", "&amp;").replaceAll("\"", "&quot;")
                                    .replaceAll("'", "&#x27;").replaceAll("/", "&#x2F;") : "";
    }
}
