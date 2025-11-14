import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.owasp.esapi.ESAPI;

public class XSSFixedServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String userInput = request.getParameter("input");
        PrintWriter out = response.getWriter();
        
        out.println("<html>");
        out.println("<head><title>XSS Fixed Page</title></head>");
        out.println("<body>");
        
        if(userInput != null){
            String safeUserInput = ESAPI.encoder().encodeForHTML(userInput);
            out.println("<h1>Hello, " + safeUserInput + "</h1>"); 
        } else {
            out.println("<h1>Hello, Guest</h1>"); 
        }
        out.println("</body>");
        out.println("</html>");
    }
}
