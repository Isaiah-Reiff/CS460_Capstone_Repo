import java.io.IOException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class XSSSafeServlet extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String userInput = request.getParameter("input");

        String safeUserInput = encodeHTML(userInput);

        String output = "<html><body>User input: " + safeUserInput + "</body></html>";

        response.getWriter().write(output);
    }

    private String encodeHTML(String input) {
        if (input == null) {
            return "";
        }
        
        StringBuilder encodedString = new StringBuilder();
        
        for (char c : input.toCharArray()) {
            switch(c) {
                case '<':
                    encodedString.append("&lt;");
                    break;
                case '>':
                    encodedString.append("&gt;");
                    break;
                case '&':
                    encodedString.append("&amp;");
                    break;
                case '"':
                    encodedString.append("&quot;");
                    break;
                case '\'':
                    encodedString.append("&#x27;");
                    break;
                case '/':
                    encodedString.append("&#x2F;");             
                    break;
                default:
                    encodedString.append(c);
            }
                
        }
        return encodedString.toString();

    }
}