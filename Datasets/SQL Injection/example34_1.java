public static void method67(String[] args) {
    String userInput = args[0];
    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        String query = "SELECT * FROM users WHERE username='" + userInput + "'";
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            System.out.println("User found: " + rs.getString("username"));
        }
        conn.close();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}