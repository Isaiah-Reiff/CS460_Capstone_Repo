public static void method55(String[] args) {
    String userInput = "filename.ser";
    try (FileInputStream fileIn = new FileInputStream(userInput);
         ObjectInputStream in = new ObjectInputStream(fileIn)) {
        Object obj = in.readObject();
        System.out.println("Deserialized object: " + obj.toString());
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}