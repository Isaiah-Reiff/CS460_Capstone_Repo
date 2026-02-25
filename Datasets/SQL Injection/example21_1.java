public static void method41(String[] args) {
    try {
        String userInput = "serialized_object_here";
        ByteArrayInputStream bis = new ByteArrayInputStream(userInput.getBytes());
        ObjectInputStream ois = new ObjectInputStream(bis);
        Object obj = ois.readObject();
        if (obj instanceof String) {
            String str = (String) obj;
            System.out.println("Deserialized string: " + str);
        }
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}