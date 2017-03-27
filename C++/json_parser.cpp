#include "json_parser.hpp"
#include "json_list.hpp"

JSONObject* JSONParser::get_obj_from_str(std::string str) {
    // Check if surrounded by quotes, list brackets, or nothing
    if (str[0] == '[' && str[str.length() - 1] == ']')
      return new JSONList(str.substr(1, str.length() - 2));
    else if (str[0] == '"' && str[str.length() - 1] == '"')
      return new JSONObject(str.substr(1, str.length() - 2));
    else
      return new JSONObject(str);
}
