import java.io.*;

public class method39 {

    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a file name to display its contents: ");
            String fileName = br.readLine();

            if (!isValidFileName(fileName)) {
                System.out.println("Invalid file name. Please try again.");
                return;
            }

            ProcessBuilder pb = new ProcessBuilder("cat", fileName);

            Process process = pb.start();

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

    private static boolean isValidFileName(String fileName) {
        return fileName != null && !fileName.isEmpty();
    }
}