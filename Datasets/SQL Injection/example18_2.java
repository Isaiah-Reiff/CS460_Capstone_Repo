import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class method36 {

    public static void main(String[] args) {

        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a command to execute: ");
            String input = reader.readLine();

            String[] command = {"/bin/sh", "-c", input};

            Process process = new ProcessBuilder(command).start();

            BufferedReader outputReader =
                new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;

            while ((line = outputReader.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}