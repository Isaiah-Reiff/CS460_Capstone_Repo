import java.sql.*;

public class method51 {
    public static void main(String[] args) {
        try {
            String userInput = "admin'; DROP TABLE users; --";

            String url = "jdbc:mysql://localhost:3306/mydatabase";
            String username = "root";
            String password = "password";

            Connection conn = DriverManager.getConnection(url, username, password);

            String query = "SELECT * FROM users WHERE username=?";
            PreparedStatement pstmt = conn.prepareStatement(query);
            pstmt.setString(1, userInput);

            ResultSet rs = pstmt.executeQuery();

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