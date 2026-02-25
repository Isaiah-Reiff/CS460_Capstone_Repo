public static void method58(String[] args) {
    String userInput = "rO0ABXNyACxqYXZhLnV0aWwuUHJpb3JpdHlTZXR1cAAAAAAAAAAAAAABdwgAAAAB1cQB+AAJMAAN0AAhjb20uZXhhbXBsZS5TdWJqZWN0AAAAAAAAAAAAA";
    try {
        ByteArrayInputStream bis = new ByteArrayInputStream(java.util.Base64.getDecoder().decode(userInput));
        ObjectInput in = new ObjectInputStream(bis);
        Object obj = in.readObject();
        System.out.println(obj.toString());
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}