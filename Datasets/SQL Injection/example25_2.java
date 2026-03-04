public static void method50(String[] args) {
    try {
        String userInput = "aced0005737200176a6176612e6c616e672e537472696e673badd256e7e91d7b47020000787000000001770400026162787200106a6176612e6c616e672e4f626a656374";
        byte[] serializedObject = hexStringToByteArray(userInput);
        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(serializedObject));
        Object obj = ois.readObject();
        System.out.println(obj.toString());
    } catch (Exception e) {
        e.printStackTrace();
    }
}

public static byte[] hexStringToByteArray(String s) {
    int len = s.length();
    byte[] data = new byte[len / 2];
    for (int i = 0; i < len; i += 2) {
        data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
                + Character.digit(s.charAt(i+1), 16));
    }
    return data;
}