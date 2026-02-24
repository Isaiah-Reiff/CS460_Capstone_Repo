// VULN: executes user-provided Groovy code
import groovy.lang.GroovyShell;
public class V042 {
  public static void main(String[] args) {
    String src = args.length > 0 ? args[0] : "return 3";
    System.out.println(new GroovyShell().evaluate(src)); // CWE-94
  }
}