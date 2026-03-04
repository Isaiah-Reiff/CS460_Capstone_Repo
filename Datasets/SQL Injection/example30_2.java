public static void method60(String[] args) {
    String userInput = "rO0ABXNyAA5qYXZhLmxhbmcuU3RyaW5n7vPdV4lZp8ABUwAAWNydAASTGphdmEvbGFuZy9TdHJpbmc7eHBzcgA+aW1wbA==";
    try {
        byte[] serializedData = java.util.Base64.getDecoder().decode(userInput);
        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(serializedData));
        Object obj = ois.readObject();
        if (obj instanceof String) {
            System.out.println("Deserialized object: " + obj);
        } else {
            System.out.println("Invalid object type");
        }
    } catch (Exception e) {
        e.printStackTrace();
    }
}

// 344524