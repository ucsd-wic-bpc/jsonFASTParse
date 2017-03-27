#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include <string>
#include <utility>
#include <cstdlib>

class JSONObject {
  private:
    std::string data;

  public:
    JSONObject();
    JSONObject(std::string data);

    template <typename T>
    T cast_data();

    template <typename T>
    std::pair<T*, int> cast_to_list();
};

template <> int JSONObject::cast_data() {
  return atoi(this->data.c_str());
}

template <> double JSONObject::cast_data() {
  return atof(this->data.c_str());
}

template <> char JSONObject::cast_data() {
  return this->data[0];
}

template <> bool JSONObject::cast_data() {
  return this->data == "true";
}

template <> std::string JSONObject::cast_data() {
  return this->data;
}

#endif
