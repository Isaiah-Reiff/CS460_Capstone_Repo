public static void method53(String[] args) {
    String serializedObject = "rO0ABXNyABdqYXZhLnV0aWwuRGVmYXVsdFdpdGhQcm94eQAAAAAAAAABAgACSgAEbWFza3hwAAAAAAAAAARzcQB+AAIAAAADdwQAAAACdAABAAJ0AAEBAICfAAGc3EAfgACAAAAAnEAAn5yABBqYXZhLmxhbmcuTnVtYmVyhqyVHQuU4CAAB4cAAAAAJ1cgACWgACWgAKAAAAAXNyABFqYXZhLmxhbmcuU3RhY2txAQj5e/uN9sgwCAAFKAAZhcHBzcQB+AAs";
    try {
        byte[] data = java.util.Base64.getDecoder().decode(serializedObject);
        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(data));
        Object obj = ois.readObject();
        System.out.println(obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}