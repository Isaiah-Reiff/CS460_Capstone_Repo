import java.io.*;
import org.apache.commons.text.StringEscapeUtils;

public class XSSSecureCode {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter your name: ");
        String name = reader.readLine();
        
        
        String sanitizedName = StringEscapeUtils.escapeHtml4(name);
        
        System.out.println("Hello, " + sanitizedName + "!");
    }
}