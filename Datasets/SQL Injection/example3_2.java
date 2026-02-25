import java.sql.*;

public class method6 {

    public static void main(String[] args) {
        try {
            String userInput = "'; DROP TABLE users; --";
            Connection connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "username",
                "password"
            );

            String query = "SELECT * FROM users WHERE username = ?";
            PreparedStatement preparedStatement = connection.prepareStatement(query);

            preparedStatement.setString(1, userInput);

            ResultSet resultSet = preparedStatement.executeQuery();

            while (resultSet.next()) {
                System.out.println(resultSet.getString("username"));
                System.out.println(resultSet.getString("email"));
            }

            resultSet.close();
            preparedStatement.close();
            connection.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}