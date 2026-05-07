public static void method88(String[] args) {
    String userInput = "smith'; DROP TABLE users; --";

    try {
        String query = "SELECT * FROM users WHERE username = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(query);
        preparedStatement.setString(1, userInput);

        ResultSet resultSet = preparedStatement.executeQuery();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}