public static void method63(String[] args) {
    String userInput = "admin'; DROP TABLE users; --";

    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");

        String query = "SELECT * FROM users WHERE username = ?";
        PreparedStatement pstmt = conn.prepareStatement(query);
        pstmt.setString(1, userInput);

        ResultSet rs = pstmt.executeQuery();

        while (rs.next()) {
            System.out.println(rs.getString("username"));
        }

        conn.close();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}