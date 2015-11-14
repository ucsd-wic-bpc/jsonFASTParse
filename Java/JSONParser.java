/*
 * jsonFASTParse
 * @author: Brandon Milton
 * http://brandonio21.com
 *
 * A small Java library meant to parse JSON in a quick fashion, given that the
 * end-user is aware of the JSON data schema. Does not support dictionaries.
 */

class JSONParser {

  public static JSONObject getObjectFromString(String str) {
    // Check if surrounded by quotes, list brackets, or nothing
    if (str.charAt(0) == '[' && str.charAt(str.length() - 1) == ']')
      return new JSONList(str.substring(1, str.length() - 1));
    else if (str.charAt(0) == '"' && str.charAt(str.length() - 1) == '"')
      return new JSONObject(str.substring(1, str.length() - 1));
    else
      return new JSONObject(str);
  }

}

