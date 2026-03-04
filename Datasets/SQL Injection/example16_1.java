import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class method31 {

    public static void main(String[] args) throws IOException, InterruptedException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter a file name: ");
        String fileName = reader.readLine();

        if (!isValidFileName(fileName)) {
            System.out.println("Invalid file name");
            return;
        }

        ProcessBuilder processBuilder = new ProcessBuilder("cat", fileName);

        Process process = processBuilder.start();

        BufferedReader inputReader =
            new BufferedReader(new InputStreamReader(process.getInputStream()));

        String line;

        while ((line = inputReader.readLine()) != null) {
            System.out.println(line);
        }

        process.waitFor();
    }

    private static boolean isValidFileName(String fileName) {
        return fileName != null && !fileName.isEmpty();
    }
}