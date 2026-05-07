public static void method61(String[] args) {
    try {
        String userInput = "1'; DROP TABLE users;--";
        String query = "SELECT * FROM users WHERE id = '" + userInput + "'";

        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(query);

        while (rs.next()) {
            System.out.println(rs.getString("username"));
            System.out.println(rs.getString("email"));
        }

    } catch (SQLException e) {
        e.printStackTrace();
    }
}