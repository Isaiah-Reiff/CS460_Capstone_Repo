
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class XSSFixedServlet extends HttpServlet {
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String userInput = request.getParameter("input");
        
        
        String sanitizedInput = sanitizeUserInput(userInput);
        
        PrintWriter out = response.getWriter();
        out.println("<html>");
        out.println("<body>");
        out.println("<h1>User Input: " + sanitizedInput + "</h1>"); 
        out.println("</body>");
        out.println("</html>");
    }
    
    private String sanitizeUserInput(String userInput) {
        if (userInput == null) {
            return "";
        }
        
        
        return userInput.replace("&", "& amp;")
                        .replace("<", "&lt;")
                        .replace(">", "&gt;")
                        .replace("\"", "&quot;")
                        .replace("'", "&#x27;")
                        .replace("/", "&#x2F;");
    }
}