public static void method54(String[] args) {
    String userInput = "serialized_object_here";
    try {
        ByteArrayInputStream bis = new ByteArrayInputStream(userInput.getBytes());
        ObjectInput in = new ObjectInputStream(bis);
        Object obj = in.readObject();
        in.close();
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}