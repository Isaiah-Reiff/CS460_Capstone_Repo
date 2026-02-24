import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

import org.apache.commons.text.StringEscapeUtils;

public class SecureServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        
        PrintWriter out = response.getWriter();
        
        out.println("<html>");
        out.println("<head><title>XSS Prevention Example</title></head>");
        out.println("<body>");
        out.println("<h1>Hello, " + StringEscapeUtils.escapeHtml4(userInput) + "</h1>"); 
        out.println("</body>");
        out.println("</html>");
    }
}