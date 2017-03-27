#include "json_object.hpp"
#include "json_list.hpp"

JSONObject::JSONObject() {
  this->data = "";
}

JSONObject::JSONObject(std::string data) {
  this->data = data;
}

template <typename T>
std::pair<T*, int> JSONObject::cast_to_list() {
  JSONList* thisList = (JSONList*) this;
  int len = thisList->get_entry_count();
  T* arr = new T[len];
  for (int ii = 0; ii < len; ii++)
    arr[ii] = thisList->get_item(ii)->cast_data<T>();
  return std::make_pair(arr, len);
}
