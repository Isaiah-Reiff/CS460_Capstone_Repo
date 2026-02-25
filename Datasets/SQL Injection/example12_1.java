import java.sql.*;

public class method23 {

    public static void main(String[] args) {

        String userInput = "'; DROP TABLE users; --";

        try {
            Connection conn = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "username",
                "password"
            );

            String query = "SELECT * FROM users WHERE username=?";
            PreparedStatement pstmt = conn.prepareStatement(query);
            pstmt.setString(1, userInput);

            ResultSet rs = pstmt.executeQuery();

            while (rs.next()) {
                System.out.println(rs.getString("username"));
            }

            rs.close();
            pstmt.close();
            conn.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}