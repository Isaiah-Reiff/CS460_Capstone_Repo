import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class XSSVulnerableServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        String output = "<html><body>Welcome " + userInput + "</body></html>";

        PrintWriter out = response.getWriter();
        out.println(output);
    }
}