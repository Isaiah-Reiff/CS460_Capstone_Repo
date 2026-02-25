public static void method45(String[] args) {
    try {
        FileInputStream fileIn = new FileInputStream("userInput.ser");
        ObjectInputStream in = new ObjectInputStream(fileIn);
        Object obj = in.readObject();
        System.out.println(obj);
        in.close();
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}