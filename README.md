JSONFastParse
============
A collection of quick and dirty classes for parsing JSON in various languages
where JSON parsers are not included in the standard libraries. This was 
originally created as a small library for use in template files for programming
competitions built with [PyCFramework](https://github.com/brandonio21/pycframework).


### Languages ###
The following languages are supported:  
* Java
* C++


### JSON Constructs ###
The following JSON Constructs are supported:  
* Strings
* Integers
* Doubles
* Lists

Quick Start Guide
-----------------

#### Retrieving a list of strings from JSON ####
Java
```java
JSONList stringList = (JSONList) JSONParser.getObjectFromString(str);
for (int i = 0; i < stringList.getEntryCount(); ++i)
	System.out.println(stringList.getItem(i).getData());
```


C++
```cpp
JSONList* stringList = (JSONList*) JSONParser::getObjectFromString(str);
for (int i = 0; i < stringList->get_entry_count(); ++i)
	cout << stringList->get_item(i)->get_data() << endl;
```


#### Retrieving a list of chars from JSON ####
Java
```java
JSONList stringList = (JSONList) JSONParser.getObjectFromString(str);
for (int i = 0; i < stringList.getEntryCount(); ++i)
	System.out.println(stringList.getItem(i).castToChar());
```


C++
```cpp
JSONList* stringList = (JSONList*) JSONParser::getObjectFromString(str);
for (int i = 0; i < stringList->get_entry_count(); ++i)
	cout << stringList->get_item(i)->cast_data<char>() << endl;
```

