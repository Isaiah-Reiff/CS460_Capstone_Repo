import java.io.*;
import java.util.*;

public class XSSVulnerability {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter your name: ");
        String userInput = scanner.nextLine();
        
        System.out.println("Hello, " + userInput + "!"); 
        
        scanner.close();
    }
}