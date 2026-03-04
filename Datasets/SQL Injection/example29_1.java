public static void method57(String[] args) {
    String userInput = "rO0ABXNyACdjb20uZXhhbXBsZS5Vc2VySW5mbyRJbmZvVXNlcgAAAAAAAAABAgACSQAKc2VyaWFsTnVtYmVyAAJbQqzzF/gGCFTgAgAAeHAAAAABdwQAAAADcQB+AAwAAAAEAAAAAXEAfgAJAAAAAG/wAAAAB4";
    try {
        ByteArrayInputStream bis = new ByteArrayInputStream(java.util.Base64.getDecoder().decode(userInput));
        ObjectInputStream ois = new ObjectInputStream(bis);
        Object obj = ois.readObject();
        User user = (User) obj;
        System.out.println(user);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}

static class User implements Serializable {
    private int id;
    public User(int id) {
        this.id = id;
    }
}