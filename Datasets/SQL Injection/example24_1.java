public static void method47(String[] args) {
    try {
        String userInput = "serialized_object_here";
        ByteArrayInputStream bais = new ByteArrayInputStream(userInput.getBytes());
        ObjectInputStream ois = new ObjectInputStream(bais);
        Object obj = ois.readObject();
        System.out.println("Deserialized object: " + obj.toString());
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}