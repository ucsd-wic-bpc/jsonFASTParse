#ifndef JSON_LIST_HPP
#define JSON_LIST_HPP

#include <vector>
#include <map>
#include <stack>
#include <string>

#include "json_object.hpp"

class JSONList : public JSONObject {
  private:
    std::vector<JSONObject*> entries;
    std::map<char, char> wrapCharacters;

    bool is_delim_char(char c);
    char get_closing_delim_from_stack(std::stack<char>& stack);
    void populate_entries_from_string(std::string str);

  public:
    JSONList(std::string data);

    JSONObject* get_item(int index);
    int get_entry_count();

    ~JSONList();
};

#endif
