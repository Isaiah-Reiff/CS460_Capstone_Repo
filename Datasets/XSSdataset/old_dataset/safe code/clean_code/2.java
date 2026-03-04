import java.io.*;
import org.owasp.encoder.Encode;

public class XSSFixedCode {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter your name: ");
        String userInput = reader.readLine();
        
        String encodedInput = Encode.forHtml(userInput); 
        
        System.out.println("Hello, " + encodedInput + "!");
    }
}