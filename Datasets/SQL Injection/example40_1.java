public static void method79() {
    String param = "' OR username='admin";
    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        String query = "SELECT * FROM users WHERE username='" + param + "'";
        stmt.executeQuery(query);
        conn.close();
    } catch (SQLException e) { e.printStackTrace(); }
}