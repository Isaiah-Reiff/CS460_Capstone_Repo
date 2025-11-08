import java.text.MessageFormat;
public class T {
  public static void main(String[] args) {
    String template = "Hello {0}";
    System.out.println(MessageFormat.format(template, "Bob"));
  }
}
