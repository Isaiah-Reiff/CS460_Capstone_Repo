import java.sql.*;
public class S040 {
  public static PreparedStatement build(Connection c, int id) throws Exception {
    PreparedStatement ps = c.prepareStatement("SELECT name FROM users WHERE id = ?");
    ps.setInt(1, id);
    return ps;
  }
}