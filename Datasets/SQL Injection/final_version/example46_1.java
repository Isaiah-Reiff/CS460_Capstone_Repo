public static void method91(String[] args) {
    String userInput = "'; DROP TABLE users; --";

    try {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");

        String query = "SELECT * FROM users WHERE username = '" + userInput + "'";

        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);

        while (resultSet.next()) {
            System.out.println(resultSet.getString("username"));
        }

    } catch (SQLException e) {
        e.printStackTrace();
    }
}