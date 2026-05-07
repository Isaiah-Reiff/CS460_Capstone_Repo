import java.sql.*;

public class method18 {

    public static void main(String[] args) {

        String userInput = "'; DROP TABLE users; --";
        String query = "SELECT * FROM users WHERE username = ?";

        try (
            Connection connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "username",
                "password"
            );
            PreparedStatement statement = connection.prepareStatement(query)
        ) {

            statement.setString(1, userInput);

            try (ResultSet resultSet = statement.executeQuery()) {
                while (resultSet.next()) {
                    System.out.println(resultSet.getString("username"));
                }
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}