import javax.servlet.http.*;
import java.io.*;

public class VulnerableServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String code = req.getParameter("code");

        // Dynamically compiles and loads attacker-controlled Java code
        javax.tools.JavaCompiler compiler = javax.tools.ToolProvider.getSystemJavaCompiler();

        // Attacker controls the file content
        File file = new File("UserCode.java");
        try (FileWriter fw = new FileWriter(file)) {
            fw.write(code);
        }

        // Compile
        compiler.run(null, null, null, file.getPath());

        // Load and run static initializer block
        Class<?> cls = new java.net.URLClassLoader(new java.net.URL[]{new File(".").toURI().toURL()})
                .loadClass("UserCode");

        resp.getWriter().write("Loaded: " + cls.getName());
    }
}