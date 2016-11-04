#include <stack>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
 * jsonFASTParse
 * author: Brandon Milton
 * http://brandonio21.com
 *
 * A small C++ library meant to parse JSON in a quick fashion, given that the 
 * end-user  is aware of the JSON data schema. Does not support dictionaries.
 */
class JSONObject { 
  string data;

  public:
    JSONObject() {
      this->data = "";
    }

    JSONObject(string data) {
      this->data = data;
    }

    string get_data() { return this->data; }

    template <typename T> 
    T cast_data();

    template <typename T>
    pair<T*, int> cast_to_list() {
      JSONList* thisList = (JSONList*) this;
      int len = thisList->get_entry_count();
      T* arr = new T[len];
      for (int ii = 0; ii < len; ii++)
        arr[ii] = thisList->get_item(ii)->cast_data<T>();
      return {arr, len};
    }
};

template <> int JSONObject::cast_data() {
  return stoi(this->get_data());
}

template <> double JSONObject::cast_data() {
  return stod(this->get_data());
}

template <> char JSONObject::cast_data() {
  return this->get_data()[0];
}

template <> bool JSONObject::cast_data() {
  return get_data == "true";
}


class JSONParser {
  public:
    static JSONObject* getObjectFromString(string str);

};
class JSONList : public JSONObject {
  vector<JSONObject*> entries;
  map<char, char> wrapCharacters;

  public:
    JSONList(string data) {
      this->wrapCharacters['['] = ']';
      this->wrapCharacters['"'] = '"';
      this->populate_entries_from_string(data);
    }

    JSONObject* get_item(int index) {
      return this->entries.at(index);
    }

    int get_entry_count() {
      return this->entries.size();
    }

    ~JSONList() {
      for (auto it = this->entries.begin(); it != this->entries.end(); it++)
        delete(*it);
    }

  private:
    bool isDelimiterCharacter(char c) {
      try {
        char temp = this->wrapCharacters.at(c);
      } 
      catch (const out_of_range& oor) {
        return false;
      }
      return true;
    }

    char getClosingDelimFromStack(stack<char>& stack) {
      return this->wrapCharacters.at(stack.top());
    }

    void populate_entries_from_string(string str) {
      stack<char> delimiter_stack;
      string current_string;

      for (int i = 0; i < str.length(); ++i) {
        if (!delimiter_stack.empty() && 
            str[i] == getClosingDelimFromStack(delimiter_stack))
          delimiter_stack.pop();
        else if (isDelimiterCharacter(str[i]))
          delimiter_stack.push(str[i]);

        // Check to see if we have reached a comma
        if ((str[i] == ',' || i == str.length() - 1) && delimiter_stack.empty()) {
          // Check if last item
          if (i == str.length() - 1) current_string.push_back(str[i]);
          this->entries.push_back(JSONParser::getObjectFromString(current_string));
          current_string.erase(0, string::npos);
          continue;
        }
        current_string.push_back(str[i]);
      }
    }
};

JSONObject* JSONParser::getObjectFromString(string str) {
    // Check if surrounded by quotes, list brackets, or nothing
    if (str[0] == '[' && str[str.length() - 1] == ']')
      return new JSONList(str.substr(1, str.length() - 2));
    else if (str[0] == '"' && str[str.length() - 1] == '"')
      return new JSONObject(str.substr(1, str.length() - 2));
    else
      return new JSONObject(str);
}
