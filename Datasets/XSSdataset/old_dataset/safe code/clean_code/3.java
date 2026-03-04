import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.owasp.esapi.ESAPI;
import org.owasp.esapi.Encoder;

public class XSSSafeServlet extends HttpServlet {
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        
        String userInput = request.getParameter("input");
        
        out.println("<html>");
        out.println("<head><title>XSS Safe Page</title></head>");
        out.println("<body>");
        
        
        Encoder encoder = ESAPI.encoder();
        String encodedUserInput = encoder.encodeForHTML(userInput);
        out.println("<p>User Input: " + encodedUserInput + "</p>");
        
        out.println("</body>");

    }
    out.println("</html>");
}