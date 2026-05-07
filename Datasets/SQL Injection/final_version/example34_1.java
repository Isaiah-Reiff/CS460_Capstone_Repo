public static void method67(String[] args) {
    try {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();

        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");

        String query = "SELECT * FROM users WHERE username=?";
        PreparedStatement preparedStatement = connection.prepareStatement(query);
        preparedStatement.setString(1, username);

        ResultSet resultSet = preparedStatement.executeQuery();

        while(resultSet.next()) {
            System.out.println("User found: " + resultSet.getString("username"));
        }

        preparedStatement.close();
        connection.close();
    } catch (Exception e) {
        e.printStackTrace();
    }
}