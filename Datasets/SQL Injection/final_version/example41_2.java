public static void method82(String[] args) {
    try {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();

        String query = "SELECT * FROM users WHERE username = '" + username + "'";

        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);

        while (resultSet.next()) {
            System.out.println("User found: " + resultSet.getString("username"));
        }

        connection.close();
    } catch (Exception e) {
        e.printStackTrace();
    }
}