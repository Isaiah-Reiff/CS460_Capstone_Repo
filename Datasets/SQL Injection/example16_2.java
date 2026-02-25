import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class method32 {

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter a file name: ");
        String fileName = reader.readLine();

        Process process = Runtime.getRuntime().exec("cat " + fileName);

        BufferedReader inputReader =
            new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;

        while ((line = inputReader.readLine()) != null) {
            System.out.println(line);
        }

        try {
            process.waitFor();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}