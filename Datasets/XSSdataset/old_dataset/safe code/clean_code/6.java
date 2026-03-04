import java.io.*;
import java.util.*;

import org.apache.commons.text.StringEscapeUtils; 

public class SecureXSSProtection {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String userInput = scanner.nextLine();

        String sanitizedInput = StringEscapeUtils.escapeHtml4(userInput); 

        System.out.println("Hello, " + sanitizedInput + "!");

        scanner.close();
    }
}