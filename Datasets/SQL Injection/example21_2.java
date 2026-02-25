public static void method42(String[] args) {
    try {
        String userInput = "SerializedDataHere";
        ByteArrayInputStream bais = new ByteArrayInputStream(userInput.getBytes());
        ObjectInputStream ois = new ObjectInputStream(bais);
        Object obj = ois.readObject();
        System.out.println("Deserialized object: " + obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}