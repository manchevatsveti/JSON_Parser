#pragma once
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"

class JsonValueFactory
{
	static JsonValue* parseObject(std::ifstream& ifs);
	static JsonValue* parseArray(std::ifstream& ifs);
	static void parseKey(std::ifstream& ifs, MyString& key);

public:
	static JsonValue* jsonValueFactory(JsonValueType type);
	static JsonValue* jsonValueFactory(JsonValueType type, std::ifstream& ifs);
	static JsonValue* parseValue(std::ifstream& ifs);
};

