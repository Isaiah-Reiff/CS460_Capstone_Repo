public static void method43(String[] args) {
    try {
        String userInput = "rO0ABXNyACRqYXZhLm5hbWVkLlN0cmluZzAAAAAAAAAAAQIAAUwAA21hcHQADExqYXZhL2xhbmcvU3RyaW5nO0wACnByb2Nlc3NvcmllcwcQAANSQAEbmFtZQEAc2lnbmluZwEA";
        ByteArrayInputStream bis = new ByteArrayInputStream(java.util.Base64.getDecoder().decode(userInput));
        ObjectInput in = new ObjectInputStream(bis);
        Object obj = in.readObject();
        System.out.println("Deserialized object: " + obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}