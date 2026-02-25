public static void method61(String[] args) {
    String userInput = "'; DROP TABLE users; --";
    try {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        String query = "SELECT * FROM users WHERE username = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(query);
        preparedStatement.setString(1, userInput);
        ResultSet resultSet = preparedStatement.executeQuery();
        while (resultSet.next()) {
            System.out.println(resultSet.getString("username"));
        }
        connection.close();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}