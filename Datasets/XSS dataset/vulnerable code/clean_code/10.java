import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class XSSVulnerableServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        String output = "<h1>Welcome " + userInput + "</h1>";

        PrintWriter out = response.getWriter();
        out.println(output);
    }
}