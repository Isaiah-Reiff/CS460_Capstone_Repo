import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class method30 {

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter a command to execute: ");
        String command = reader.readLine();

        String[] sanitizedCommand = {"/bin/sh", "-c", command};

        ProcessBuilder processBuilder = new ProcessBuilder(sanitizedCommand);
        Process process = processBuilder.start();

        BufferedReader outputReader =
            new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;

        while ((line = outputReader.readLine()) != null) {
            System.out.println(line);
        }
    }
}