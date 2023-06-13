#pragma once
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"

class JsonValueFactory
{
	static JsonValue* parseObject(std::istream& ifs);
	static JsonValue* parseArray(std::istream& ifs);
	static void parseKey(std::istream& ifs, MyString& key);

public:
	static JsonValue* jsonValueFactory(JsonValueType type);
	static JsonValue* jsonValueFactory(JsonValueType type, std::istream& ifs);
	static JsonValue* parseValue(std::istream& ifs);
};

