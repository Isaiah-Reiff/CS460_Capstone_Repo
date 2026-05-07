public static void method62(String[] args) {
    try {
        String userInput = "1'; DROP TABLE users;--";
        String query = "SELECT * FROM users WHERE id = ?";

        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        PreparedStatement pstmt = conn.prepareStatement(query);
        pstmt.setString(1, userInput);

        ResultSet rs = pstmt.executeQuery();

        while (rs.next()) {
            System.out.println(rs.getString("username"));
            System.out.println(rs.getString("email"));
        }

    } catch (SQLException e) {
        e.printStackTrace();
    }
}