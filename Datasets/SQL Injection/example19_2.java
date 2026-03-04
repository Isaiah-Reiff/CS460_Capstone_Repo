import java.io.*;

public class method38 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter a command to execute: ");
        String userInput = br.readLine();

        if (!isValidInput(userInput)) {
            System.out.println("Invalid input. Please try again.");
            return;
        }

        String[] command = {"ls", userInput};

        Process process = Runtime.getRuntime().exec(command);

        BufferedReader reader =
            new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;

        while ((line = reader.readLine()) != null) {
            System.out.println(line);
        }
    }

    private static boolean isValidInput(String userInput) {
        return userInput.matches("[a-zA-Z0-9]+");
    }
}