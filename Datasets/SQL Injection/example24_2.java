public static void method48(String[] args) {
    try {
        String userInput = "rO0ABXNyACRqYXZhLnV0aWwuQ29sbGVjdGlvbnMkQ29sbGVjdGlvbnQAAAAAAAAAAQIAAHhyACFqYXZhLmxhbmcuUnVudGltZUV4Y2VwdGlvbg==";
        byte[] serializedData = userInput.getBytes();
        ByteArrayInputStream bais = new ByteArrayInputStream(serializedData);
        ObjectInputStream ois = new ObjectInputStream(bais);
        Object obj = ois.readObject();
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}