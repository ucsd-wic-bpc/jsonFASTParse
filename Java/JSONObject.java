/*
 * jsonFASTParse
 * @author: Brandon Milton
 * http://brandonio21.com
 *
 * A small Java library meant to parse JSON in a quick fashion, given that the
 * end-user is aware of the JSON data schema. Does not support dictionaries.
 */

class JSONObject {
  private String data;

  public JSONObject() {
    this.data = "";
  }

  public JSONObject(String data) {
    this.data = data;
  }

  public String getData() {
    return this.data;
  }

  public String castToString() {
    return this.data;
  }

  public int castToInt() {
    return Integer.parseInt(this.data);
  }

  public double castToDouble() {
    return Double.parseDouble(this.data);
  }

  public char castToChar() {
    return this.data.charAt(0);
  }

  public boolean castToBool() {
    return Boolean.parseBoolean(this.data);
  }

}

