public static void method76() {
    String input = "'; UPDATE users SET password='hack' --";
    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        String query = "SELECT * FROM users WHERE username='" + input + "'";
        stmt.executeQuery(query);
        conn.close();
    } catch (SQLException e) { e.printStackTrace(); }
}