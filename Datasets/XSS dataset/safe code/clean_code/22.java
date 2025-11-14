import org.apache.commons.text.StringEscapeUtils;
import java.io.*;

public class SecureXSSDemo {

    public static void main(String[] args) {
        
        String userInput = "<script>alert('XSS Vulnerability!')</script>";

        
        String sanitizedInput = StringEscapeUtils.escapeHtml4(userInput);

        
        String outputHtml = "<html><body><h1>Welcome " + sanitizedInput + "</h1></body></html>";

        try {
            FileWriter fileWriter = new FileWriter("output.html");
            PrintWriter printWriter = new PrintWriter(fileWriter);
            printWriter.print(outputHtml);
            printWriter.close();
            System.out.println("Output written to output.html");
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}