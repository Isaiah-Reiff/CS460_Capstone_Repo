import java.io.*;

public class XSSSecureServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String userInput = request.getParameter("input");
        PrintWriter out = response.getWriter();
        
        out.println("<html>");
        out.println("<body>");
        
        out.println("User input: " + escapeHtml(userInput));
        out.println("</body>");
        out.println("</html>");
    }
    
    private String escapeHtml(String input) {
        if (input == null) {
            return "";
        }
        
        StringBuilder builder = new StringBuilder();
        
        for (char c : input.toCharArray()) {
            switch(c) {
                case '<':
                    builder.append("&lt;");
                    break;
                case '>':
                    builder.append("&gt;");
                    break;
                case '&':
                    builder.append("&amp;");
                    break;
                case '"':
                    builder.append("&quot;");
                    break;
                case '\'':
                    builder.append("&#x27;");
                    break;              
                case '/':
                    builder.append("&#x2F;");                   
                    break;
                default:
                    builder.append(c);          
            }
        }       
        return builder.toString();
    }
}