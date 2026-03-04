public static void method46(String[] args) {
    try {
        String userInput = "rO0ABXNyACdjb20uZXhhbXBsZS5Vc2VySW5wdXRBc3NlbWJseWluZ1N0b3Jlh2GvG8LmHAIAAUwAAUwBAAhleGVjAQAGamF2YXgAAgEAAQAJZGVzdHN0cmVhbRQAEGphdmFzdAASW0hTG9yZWdpYmVkUHJvcGVydHlFbnVtZXJhdG9yO3hwc3IADmphdmEubGFuZy5FeGVjdXRlSGFzaFNldA==";
        ByteArrayInputStream bais = new ByteArrayInputStream(userInput.getBytes());
        ObjectInputStream ois = new ObjectInputStream(bais);
        Object obj = ois.readObject();
        System.out.println(obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}