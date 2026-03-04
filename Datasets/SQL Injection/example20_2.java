import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class method40 {

    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a file name to display its contents: ");
            String fileName = br.readLine();

            String command = "cat " + fileName;

            Process process = Runtime.getRuntime().exec(command);

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
}