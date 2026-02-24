import java.util.*;
public class S049 {
  public static void main(String[] args) {
    String col = args.length>0?args[0]:"status";
    Set<String> allowed = Set.of("status","type_id");
    if (!allowed.contains(col)) { System.out.println("bad"); return; }
    String sql = "SELECT id FROM items WHERE " + col + " = ?";
    System.out.println(sql);
  }
}