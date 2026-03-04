public static void method59(String[] args) {
    try {
        FileInputStream fis = new FileInputStream("serialized_data.ser");
        ObjectInputStream ois = new ObjectInputStream(fis);
        Object obj = ois.readObject();
        if (obj instanceof String) {
            String str = (String) obj;
            System.out.println("Deserialized String: " + str);
        }
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}