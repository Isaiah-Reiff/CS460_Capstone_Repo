import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.apache.commons.text.StringEscapeUtils;

public class XSSFixedServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        String sanitizedInput = StringEscapeUtils.escapeHtml4(userInput);
        String output = "<html><body>Welcome " + sanitizedInput + "</body></html>";

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println(output);
    }
}