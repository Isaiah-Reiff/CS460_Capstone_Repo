// 404849

public static void method71() {
    String userInput = "'; DROP TABLE users; --";
    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        String query = "SELECT * FROM users WHERE username='" + userInput + "'";
        stmt.executeQuery(query);
        conn.close();
    } catch (SQLException e) { e.printStackTrace(); }
}