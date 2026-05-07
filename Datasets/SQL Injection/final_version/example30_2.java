import java.io.*;
import javax.xml.bind.DatatypeConverter;

public class method60 {
    public static void main(String[] args) {
        String userInput = "rO0ABXNyAA5qYXZhLmxhbmcuU3RyaW5n7vPdV4lZp8ABUwAAWNydAASTGphdmEvbGFuZy9TdHJpbmc7eHBzcgA+aW1wbA==";

        try {
            byte[] serializedData = DatatypeConverter.parseBase64Binary(userInput);
            ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(serializedData));
            Object obj = ois.readObject();
            System.out.println(obj);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}