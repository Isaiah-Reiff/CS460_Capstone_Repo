import java.sql.*;

public class method52 {
    public static void main(String[] args) {
        try {
            String userInput = "admin'; DROP TABLE users; --";

            String url = "jdbc:mysql://localhost:3306/mydatabase";
            String username = "root";
            String password = "password";

            Connection conn = DriverManager.getConnection(url, username, password);
            Statement stmt = conn.createStatement();

            String query = "SELECT * FROM users WHERE username='" + userInput + "'";
            ResultSet rs = stmt.executeQuery(query);

            while (rs.next()) {
                System.out.println("Username: " + rs.getString("username"));
                System.out.println("Password: " + rs.getString("password"));
            }

            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}