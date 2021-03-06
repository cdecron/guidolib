package drawcommand;

   
public class OffsetOriginCommand implements PrintableDrawCommand {

  public float _x;
  public float _y;

  public OffsetOriginCommand(float x, float y) {
    super();
    _x = x;
    _y = y;
  }

  @Override
  public String asString() {
    StringBuilder out = new StringBuilder();
    out.append("OffsetOrigin");
    out.append(" ");
    out.append(_x);
    out.append(" ");
    out.append(_y);
    return out.toString();
  }

}
