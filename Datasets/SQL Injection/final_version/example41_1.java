public static void method81(String[] args) {
    String userInput = "'; DROP TABLE users; --";

    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");

        String query = "SELECT * FROM users WHERE username=?";
        PreparedStatement stmt = conn.prepareStatement(query);
        stmt.setString(1, userInput);

        ResultSet rs = stmt.executeQuery();

        while (rs.next()) {
            System.out.println("User ID: " + rs.getInt("id") + ", Username: " + rs.getString("username"));
        }

        conn.close();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}