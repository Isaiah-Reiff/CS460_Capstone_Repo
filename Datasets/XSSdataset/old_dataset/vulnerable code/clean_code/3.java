import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class XSSVulnerableServlet extends HttpServlet {
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        
        String userInput = request.getParameter("input");
        
        out.println("<html>");
        out.println("<head><title>XSS Vulnerable Page</title></head>");
        out.println("<body>");
        
        
        out.println("<p>User Input: " + userInput + "</p>");
        
        out.println("</body>");
        out.println("</html>");
    }
}