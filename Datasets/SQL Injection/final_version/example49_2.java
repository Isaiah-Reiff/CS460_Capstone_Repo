public static void method98(String[] args) {
    String userInput = "admin'; DROP TABLE users; --";

    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");

        String query = "SELECT * FROM users WHERE username=?";
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