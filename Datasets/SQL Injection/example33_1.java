public static void method65(String[] args) {
    try {
        String userInput = args[0];
        String url = "jdbc:mysql://localhost:3306/mydatabase";
        String username = "root";
        String password = "password";
        Connection conn = DriverManager.getConnection(url, username, password);
        Statement stmt = conn.createStatement();
        String query = "SELECT * FROM users WHERE username='" + userInput + "'";
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            System.out.println("User found: " + rs.getString("username"));
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}