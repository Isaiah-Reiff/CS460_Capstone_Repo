public static void method94(String[] args) {
    String userInput = "admin'; DROP TABLE users; --";
    String query = "SELECT * FROM users WHERE username = ?";

    try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
         PreparedStatement statement = connection.prepareStatement(query)) {

        statement.setString(1, userInput);
        ResultSet resultSet = statement.executeQuery();

        while (resultSet.next()) {
            System.out.println(resultSet.getString("username"));
        }

    } catch (SQLException e) {
        e.printStackTrace();
    }
}