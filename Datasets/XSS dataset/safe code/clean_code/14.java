import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.owasp.encoder.Encode;

public class SecureServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        String sanitizedInput = Encode.forHtml(userInput); 
        
        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<body>");
        out.println("<p>User input: " + sanitizedInput + "</p>"); 
        out.println("</body>");
        out.println("</html>");
    }
}