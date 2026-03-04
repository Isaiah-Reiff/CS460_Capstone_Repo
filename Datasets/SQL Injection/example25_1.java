public static void method49(String[] args) {
    try {
        String userInput = "rO0ABXNyACFqYXZhLmxhbmcuU3RyaW5nO5DcCR4hACwwAAS0AAUxvcmcvYXBhY2hlL01hcDt4cAAAAAAAAAABAAAAAXQABG1vZGlmaWNhdGlvbnQAEkxqYXZhL2xhbmcvU3RyaW5nO0wACnRvTm9kZU9iamVjdHQAEkxqYXZhL2xhbmcvT2JqZWN0O3hw";
        ByteArrayInputStream bis = new ByteArrayInputStream(java.util.Base64.getDecoder().decode(userInput));
        ObjectInputStream in = new ObjectInputStream(bis);
        Object obj = in.readObject();
        System.out.println(obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}