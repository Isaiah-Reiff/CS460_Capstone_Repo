import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.owasp.esapi.ESAPI;
import org.owasp.esapi.Encoder;

public class XSSSafeServlet extends HttpServlet {
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        response.setContentType("text/html");
        
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        
        
        Encoder encoder = ESAPI.encoder();
        out.println("<h2>You entered: " + encoder.encodeForHTML(userInput) + "</h2>");
        
        out.println("</body></html>");
    }
}