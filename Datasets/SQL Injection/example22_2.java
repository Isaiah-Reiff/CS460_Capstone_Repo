public static void method44(String[] args) {
    try {
        String userInput = "rO0ABXNyAChjb20uZXhhbXBsZS5JbnNlY3VyaXR5UHJvZmlsZU1hY2hpbmVNYW5hZ2VyDAAAAAABAgAJTAAEbWVzc2FnZXQAEkxqYXZhL3V0aWwvTWFwO3hwAAAAAAAAAABw";
        byte[] serializedObject = javax.xml.bind.DatatypeConverter.parseBase64Binary(userInput);
        ByteArrayInputStream bais = new ByteArrayInputStream(serializedObject);
        ObjectInputStream ois = new ObjectInputStream(bais);
        Object obj = ois.readObject();
        System.out.println(obj.toString());
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}