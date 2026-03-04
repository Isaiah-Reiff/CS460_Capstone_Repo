public static void method52(String[] args) {
    String serializedObject = "rO0ABXNyAC5qYXZheC5pbnNlY3VyZS5Db2RlSW50ZXJzdHJhY3RvciRVc2VySW50ZXJzdHJhY3QAAAAAAAAAAQIAAHhyADBqYXZheC9pbnNlY3VyZS9Db2RlO0wABGxvY2t0ABJMamF2YS9sYW5nL09iamVjdDt4cHNyACpodHRwOi8vZGF0YS5jb20ubmV0L2p1bGllbi9zdWJzY3JpcHRpb25zL2V4YW1wbGUvaW52YWxpZC9Pcmdhbml6ZUFycmF5U3lzdGVtcy9TZWN1cmVTdHJpbmc7TAAL";
    try {
        byte[] data = java.util.Base64.getDecoder().decode(serializedObject);
        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(data));
        Object obj = ois.readObject();
        System.out.println(obj);
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}