public static void method93(String[] args) {
    String userInput = "admin'; DROP TABLE users; --";
    String query = "SELECT * FROM users WHERE username = '" + userInput + "'";

    try {
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);

        while (resultSet.next()) {
            System.out.println(resultSet.getString("username"));
        }

        connection.close();

    } catch (SQLException e) {
        e.printStackTrace();
    }
}