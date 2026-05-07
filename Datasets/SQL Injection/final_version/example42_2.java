public static void method84(String[] args) {
    try {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();

        String query = "SELECT * FROM users WHERE username='" + username + "'";

        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");

        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);

        while (resultSet.next()) {
            System.out.println("User ID: " + resultSet.getInt("id") + ", Username: " + resultSet.getString("username"));
        }

    } catch (Exception e) {
        e.printStackTrace();
    }
}