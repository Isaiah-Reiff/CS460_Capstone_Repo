import java.sql.*;

public class method1 {
    public static void main(String[] args) {

        String userInput = "admin'; DROP TABLE users; --";
        try {
            Connection connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase",
                "username",
                "password"
            );

            Statement statement = connection.createStatement();

            String query = "SELECT * FROM users WHERE username='" + userInput + "'";
            ResultSet resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                System.out.println("Username: " + resultSet.getString("username"));
                System.out.println("Password: " + resultSet.getString("password"));
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}