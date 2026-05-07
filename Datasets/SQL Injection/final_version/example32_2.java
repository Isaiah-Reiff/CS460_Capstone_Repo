public static void method64(String[] args) {
    String userInput = "admin'; DROP TABLE users; --";

    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "root", "password");
        Statement stmt = conn.createStatement();

        String query = "SELECT * FROM users WHERE username = '" + userInput + "'";

        ResultSet rs = stmt.executeQuery(query);

        while (rs.next()) {
            System.out.println(rs.getString("username"));
        }

        conn.close();
    } catch (SQLException e) {
        e.printStackTrace();
    }
}