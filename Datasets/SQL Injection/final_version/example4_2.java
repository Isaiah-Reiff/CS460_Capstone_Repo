import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

public class method8 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a username: ");
        String username = scanner.nextLine();

        try {
            Connection conn = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "root",
                "password"
            );

            String query = "SELECT * FROM users WHERE username=?";
            PreparedStatement pstmt = conn.prepareStatement(query);
            pstmt.setString(1, username);

            ResultSet rs = pstmt.executeQuery();

            while (rs.next()) {
                System.out.println(
                    "User ID: " + rs.getInt("id") +
                    ", Username: " + rs.getString("username")
                );
            }

            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}