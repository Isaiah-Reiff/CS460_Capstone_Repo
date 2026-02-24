import java.io.*;
import org.owasp.encoder.Encode;

public class XSSSecureCode {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter your name: ");
        String name = br.readLine();
        
        String safeName = Encode.forHtml(name); 
        
        System.out.println("Hello, " + safeName + "!");
    }
}