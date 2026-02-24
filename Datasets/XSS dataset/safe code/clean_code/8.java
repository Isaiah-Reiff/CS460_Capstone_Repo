import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.owasp.esapi.ESAPI;
import org.owasp.esapi.codecs.HTMLEntityCodec;

public class XSSFixedServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");

        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<body>");
        
        HTMLEntityCodec htmlEncoder = new HTMLEntityCodec();
        String encodedInput = htmlEncoder.encodeForHTML(userInput);
        
        out.println("<h1>User Input: " + encodedInput + "</h1>"); 
        out.println("</body>");
        out.println("</html>");
    }
}