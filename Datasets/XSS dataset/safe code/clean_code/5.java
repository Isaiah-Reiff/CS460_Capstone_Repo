import org.owasp.encoder.Encode;

import java.util.Scanner;

public class XSSSecureCode {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String userInput = scanner.nextLine();

        
        String sanitizedInput = Encode.forHtml(userInput);

        System.out.println("Hello, " + sanitizedInput + "!"); 

        scanner.close();
    }
}