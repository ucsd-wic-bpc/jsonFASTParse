#include <stdexcept>
#include "json_list.hpp"
#include "json_parser.hpp"

JSONList::JSONList(std::string data) {
  this->wrapCharacters['['] = ']';
  this->wrapCharacters['"'] = '"';
  this->populate_entries_from_string(data);
}

JSONObject* JSONList::get_item(int index) {
  return this->entries.at(index);
}

int JSONList::get_entry_count() {
  return this->entries.size();
}

JSONList::~JSONList() {
  std::vector<JSONObject*>::iterator it;
  for (it = this->entries.begin(); it != this->entries.end(); it++)
    delete(*it);
}

bool JSONList::is_delim_char(char c) {
  try {
    char temp = this->wrapCharacters.at(c);
  } 
  catch (const std::out_of_range& oor) {
    return false;
  }
  return true;
}

char JSONList::get_closing_delim_from_stack(std::stack<char>& stack) {
  return this->wrapCharacters.at(stack.top());
}

void JSONList::populate_entries_from_string(std::string str) {
  std::stack<char> delimiter_stack;
  std::string current_string;

  for (int i = 0; i < str.length(); ++i) {
    if (!delimiter_stack.empty() && 
        str[i] == get_closing_delim_from_stack(delimiter_stack))
      delimiter_stack.pop();
    else if (is_delim_char(str[i]))
      delimiter_stack.push(str[i]);

    // Check to see if we have reached a comma
    if ((str[i] == ',' || i == str.length() - 1) && delimiter_stack.empty()) {
      // Check if last item
      if (i == str.length() - 1) current_string.push_back(str[i]);
      this->entries.push_back(JSONParser::get_obj_from_str(current_string));
      current_string.erase(0, std::string::npos);
      continue;
    }
    current_string.push_back(str[i]);
  }
}
