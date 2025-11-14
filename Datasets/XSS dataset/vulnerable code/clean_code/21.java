import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class XSSVulnerableServlet extends HttpServlet {
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        response.setContentType("text/html");
        
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h2>You entered: " + userInput + "</h2>"); 
        out.println("</body></html>");
    }
}