import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class method20 {

    public static void main(String[] args) {

        String userInput = "'; DROP TABLE users; --";

        try {
            Connection connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "username",
                "password"
            );

            String query = "SELECT * FROM users WHERE username = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, userInput);

            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
                System.out.println(resultSet.getString("username"));
            }

            resultSet.close();
            statement.close();
            connection.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}