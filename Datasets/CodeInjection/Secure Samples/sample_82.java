import java.text.MessageFormat;
public class S041 {
  public static void main(String[] args) {
    String name = args.length>0?args[0]:"Guest";
    System.out.println(MessageFormat.format("Hello {0}", name));
  }
}