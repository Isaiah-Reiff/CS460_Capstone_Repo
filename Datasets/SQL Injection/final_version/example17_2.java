import java.io.*;

public class method34 {

    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a command to execute: ");
            String userInput = br.readLine();

            if (!isValidInput(userInput)) {
                System.out.println("Invalid input. Please try again.");
                return;
            }

            ProcessBuilder processBuilder = new ProcessBuilder("ping", userInput);

            Process process = processBuilder.start();

            BufferedReader reader =
                new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;

            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean isValidInput(String input) {
        return input != null && !input.isEmpty();
    }
}