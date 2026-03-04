import java.util.Scanner;
import org.owasp.encoder.Encode;

public class SecureXSSExample {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String userInput = scanner.nextLine();

        System.out.println("Hello, " + Encode.forHtml(userInput) + "!");

        
        System.out.println("<script>alert('XSS attack!')</script>");
    }
}