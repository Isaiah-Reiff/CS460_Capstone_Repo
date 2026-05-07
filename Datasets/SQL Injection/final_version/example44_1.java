public static void method87(String[] args) {
    String userInput = "smith'; DROP TABLE users; --";
    String query = "SELECT * FROM users WHERE username = '" + userInput + "'";

    try {
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);
    } catch (SQLException e) {
        e.printStackTrace();
    }
}