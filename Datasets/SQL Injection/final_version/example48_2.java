public static void method96(String[] args) {
    try {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter username:");
        String username = scanner.nextLine();

        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
        Statement statement = connection.createStatement();

        String query = "SELECT * FROM users WHERE username='" + username + "'";
        ResultSet resultSet = statement.executeQuery(query);

        while(resultSet.next()) {
            System.out.println("User found: " + resultSet.getString("username"));
        }

    } catch (SQLException e) {
        e.printStackTrace();
    }
}