import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class XSSVulnerableServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        String output = "<p>User input: " + userInput + "</p>";

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println(output);
    }
}