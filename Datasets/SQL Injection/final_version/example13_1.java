import java.sql.*;

public class method25 {

    public static void main(String[] args) {

        try {
            String userInput = "admin'; DROP TABLE users; --";

            Connection conn = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "username",
                "password"
            );

            Statement stmt = conn.createStatement();
            String query = "SELECT * FROM users WHERE username='" + userInput + "'";

            ResultSet rs = stmt.executeQuery(query);

            while (rs.next()) {
                System.out.println(rs.getString("username"));
                System.out.println(rs.getString("password"));
            }

            rs.close();
            stmt.close();
            conn.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}