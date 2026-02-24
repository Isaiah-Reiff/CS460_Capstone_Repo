import java.util.Scanner;

public class XSSVulnerableCode {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String userInput = scanner.nextLine();

        
        System.out.println("<h1>Welcome, " + userInput + "!</h1>");

        scanner.close();
    }
}