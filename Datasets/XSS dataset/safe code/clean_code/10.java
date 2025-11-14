import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class XSSFixedServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("input");
        String safeOutput = escapeHtml(userInput);

        PrintWriter out = response.getWriter();
        out.println("<h1>Welcome " + safeOutput + "</h1>");
    }

    private String escapeHtml(String input) {
        if (input == null) {
            return "";
        }
        return input
                .replaceAll("&", "&amp;")
                .replaceAll("<", "&lt;")
                .replaceAll(">", "&gt;")
                .replaceAll("\"", "&quot;")
                .replaceAll("'", "&#39;");
    }
}