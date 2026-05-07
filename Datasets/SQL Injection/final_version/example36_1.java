public static void method71(String[] args) {
    String userInput = "'; DROP TABLE users; --";
    String query = "SELECT * FROM users WHERE username = ?";

    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        PreparedStatement stmt = conn.prepareStatement(query);
        stmt.setString(1, userInput);

        ResultSet rs = stmt.executeQuery();

        while (rs.next()) {
            System.out.println(rs.getString("username"));
        }

        conn.close();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}