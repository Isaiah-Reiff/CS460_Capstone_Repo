import java.util.*;
public class Safe {
  interface Action { Object run(Object[] a); }
  static Map<String, Action> map = Map.of(
    "sum", (args)-> ((int)args[0]) + ((int)args[1])
  );
  public static void main(String[] args) {
    Object result = map.get("sum").run(new Object[]{2,3});
    System.out.println(result);
  }
}
