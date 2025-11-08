import java.util.*;
import java.io.*;

public class SafeJavaDispatch {
    interface Action { String run(List<String> args); }

    public static void main(String[] args) throws Exception {
        Map<String, Action> allowed = new HashMap<>();
        allowed.put("greet", (a) -> "Hello " + (a.size() > 0 ? a.get(0) : "Guest"));
        allowed.put("repeat", (a) -> {
            if (a.size() < 2) return "usage: repeat <word> <count>";
            String word = a.get(0);
            int cnt;
            try { cnt = Integer.parseInt(a.get(1)); } catch (NumberFormatException e) { return "count must be integer"; }
            return String.join(" ", Collections.nCopies(Math.max(0, cnt), word));
        });

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter action and args (e.g. \"greet Alice\"): ");
        String line = br.readLine();
        if (line == null || line.trim().isEmpty()) return;
        String[] parts = line.trim().split("\\s+");
        String action = parts[0];
        List<String> aList = parts.length > 1 ? Arrays.asList(Arrays.copyOfRange(parts, 1, parts.length)) : Collections.emptyList();

        Action act = allowed.get(action);
        if (act == null) {
            System.out.println("Action not allowed.");
        } else {
            System.out.println(act.run(aList));
        }
    }
}