import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class XSSVulnerableServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String userInput = request.getParameter("input");
        PrintWriter out = response.getWriter();
        
        out.println("<html>");
        out.println("<head><title>XSS Vulnerable Page</title></head>");
        out.println("<body>");
        out.println("<h1>Hello, " + userInput + "</h1>"); 
        out.println("</body>");
        out.println("</html>");
    }
}