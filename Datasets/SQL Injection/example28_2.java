public static void method56(String[] args) {
    String userInput = "rO0ABXNyACxqYXZhLmxhbmcuU3RyaW5nurFhRwADAANJAAJpZHQAEkxqYXZhL2xhbmcvU3RyaW5nbO4y77u+fwMAAkwAA29yZy5hcGFjaGUub3JnLmNvbGxlY3Rpb25zdHJlYW3GQDdWuEVAIAAHhyAD9vcmcuYXBhY2hlLm9yZy5jb2xsZWN0aW9uc3RyZWFt6QDdVrlF7gIAAHhw";
    try {
        byte[] serializedData = javax.xml.bind.DatatypeConverter.parseBase64Binary(userInput);
        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(serializedData));
        Object obj = ois.readObject();
        System.out.println(obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}