import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.owasp.esapi.ESAPI;
import org.owasp.esapi.Encoder;

public class XSSSecureServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        
        Encoder encoder = ESAPI.encoder();
        String safeUserInput = encoder.encodeForHTML(userInput);
        
        String htmlResponse = "<html><body>User input: " + safeUserInput + "</body></html>";
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println(htmlResponse);
    }
}