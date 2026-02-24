import java.util.*;
public class S039 {
  interface A { String run(List<String> a); }
  public static void main(String[] args) {
    Map<String,A> m = Map.of(
      "greet", (a)->"Hi " + (a.isEmpty()?"Guest":a.get(0)),
      "len", (a)-> String.valueOf(a.isEmpty()?0:a.get(0).length())
    );
    String action = args.length>0?args[0]:"greet";
    List<String> rest = args.length>1?Arrays.asList(Arrays.copyOfRange(args,1,args.length)):List.of();
    System.out.println(m.containsKey(action)?m.get(action).run(rest):"not allowed");
  }
}