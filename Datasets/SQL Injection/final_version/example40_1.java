public static void method79(String[] args) {
    try {
        String userInput = args[0];

        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");

        String query = "SELECT * FROM users WHERE username='" + userInput + "'";

        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(query);

        while (rs.next()) {
            System.out.println("User ID: " + rs.getInt("id") + ", Username: " + rs.getString("username"));
        }

        rs.close();
        stmt.close();
        conn.close();
    } catch (Exception e) {
        e.printStackTrace();
    }
}