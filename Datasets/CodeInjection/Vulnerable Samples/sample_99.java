import javax.tools.*;
import java.util.*;
public class V050 {
  public static void main(String[] args) {
    String src = args.length > 0 ? args[0] :
      "public class U { public static int go(){ return 7; } }";
    JavaCompiler c = ToolProvider.getSystemJavaCompiler();
    JavaFileObject f = new SimpleJavaFileObject(java.net.URI.create("string:///U.java"), JavaFileObject.Kind.SOURCE) {
      public CharSequence getCharContent(boolean ignore) { return src; }
    };
    c.getTask(null, null, null, null, null, Arrays.asList(f)).call(); 
    System.out.println("compiled");
  }
}