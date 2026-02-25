public static void method73() {
    String user = "'; DELETE FROM users; --";
    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        String query = "SELECT * FROM users WHERE username='" + user + "'";
        stmt.executeQuery(query);
        conn.close();
    } catch (SQLException e) { e.printStackTrace(); }
}