import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.owasp.esapi.ESAPI;
import org.owasp.esapi.Encoder;

public class XSSFixedServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        Encoder encoder = ESAPI.encoder();
        String encodedUserInput = encoder.encodeForHTML(userInput);
        String output = "<p>User input: " + encodedUserInput + "</p>";

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println(output);
    }
}