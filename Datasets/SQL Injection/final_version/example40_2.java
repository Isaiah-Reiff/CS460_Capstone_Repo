public static void method80(String[] args) {
    UserAuthentication auth = new UserAuthentication();
    boolean isAuthenticated = auth.authenticateUser("admin' OR '1'='1", "password123");

    if (isAuthenticated) {
        System.out.println("User authenticated successfully.");
    } else {
        System.out.println("Authentication failed.");
    }
}