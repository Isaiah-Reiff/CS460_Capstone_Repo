public static void method66(String[] args) {
    try {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        Statement stmt = conn.createStatement();
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String username = scanner.nextLine();
        String query = "SELECT * FROM users WHERE username='" + username + "'";
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            System.out.println("User ID: " + rs.getInt("id") + ", Username: " + rs.getString("username"));
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}