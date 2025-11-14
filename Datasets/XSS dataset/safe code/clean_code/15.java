import org.owasp.encoder.Encode;

import java.util.Scanner;

public class XSSFixedCode {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String userInput = scanner.nextLine();

        
        String encodedInput = Encode.forHtml(userInput);
        System.out.println("<h1>Welcome, " + encodedInput + "!</h1>");

        scanner.close();
    }
}