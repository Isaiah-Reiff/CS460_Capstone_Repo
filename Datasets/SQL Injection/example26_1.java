public static void method51(String[] args) {
    try {
        String serializedData = "rO0ABXNyAC5qYXZheC5tYWluLlN0cmluZ0xpbmVMaXN0AAAAAAAAAAECAAB4cgAaaW1wb3J0IFN0cmluZztMAAVzdHJpbmdMaW5lcQB+AAR0eXBldAAtVGVzdCBEZXNlcmlhbGxvYwAA";
        byte[] data = java.util.Base64.getDecoder().decode(serializedData);
        ObjectInputStream in = new ObjectInputStream(new ByteArrayInputStream(data));
        TestObject obj = (TestObject) in.readObject();
        System.out.println(obj.getData());
    } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
    }
}

static class TestObject implements Serializable {
    private String data;
    public TestObject(String data) {
        this.data = data;
    }
    public String getData() {
        return data;
    }
}