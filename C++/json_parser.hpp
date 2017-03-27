#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include "json_object.hpp"

class JSONParser {
  public:
    static JSONObject* get_obj_from_str(std::string str);
};

#endif
