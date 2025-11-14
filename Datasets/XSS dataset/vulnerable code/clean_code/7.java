import java.io.*;

public class XSSVulnerableCode {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter your name: ");
        String name = reader.readLine();
        
        System.out.println("Hello, " + name + "!"); 
        
    }
}