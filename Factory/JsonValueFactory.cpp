#include "JsonValueFactory.h"
#include "../JSONValues/JsonBool.h"
#include "../JSONValues/JsonNumber.h"
#include "../JSONValues/JsonMyString.h"
#include "../JSONValues/JsonArray.h"
#include "../JSONValues/JsonObject.h"
#include "../JSONValues/JsonNull.h"
#include "../Utilities/Helper.h"

JsonValue* JsonValueFactory::jsonValueFactory(JsonValueType type)
{
	switch (type)
	{
	case JsonValueType::NUMBER:
		return new JsonNumber();
	case JsonValueType::BOOL:
		return new JsonBool();
	case JsonValueType::MYSTRING:
		return new JsonMyString();
	case JsonValueType::ARRAY:
		return new JsonArray();
	case JsonValueType::OBJECT:
		return new JsonObject();
	case JsonValueType::NULL_VALUE:
		return new JsonNull();
	}
	return nullptr;
}

JsonValue* JsonValueFactory::jsonValueFactory(JsonValueType type, std::istream& ifs)
{
	switch (type)
	{
	case JsonValueType::NUMBER:
	{
		double value;
		ifs >> value;
		return new JsonNumber(value);

	}
	case JsonValueType::BOOL: 
	{
		char buff[10];//it is a boolean (max 5 chars)
		ifs.getline(buff, 10, ',');

		bool value;
		if (strcmp(buff,"true")==0) {
			value = true;
		}
		else {
			value = false;
		}

		return new JsonBool(value);
	}
	case JsonValueType::MYSTRING:
		ifs.ignore();
		char buff[1024];//TODO: MyString with fixed length(template class for the length)
		ifs.getline(buff, 1024, '\"');
		return new JsonMyString(MyString(buff));

	case JsonValueType::ARRAY:
		return new JsonArray();

	case JsonValueType::OBJECT:
		return new JsonObject();

	case JsonValueType::NULL_VALUE:
		ifs.ignore(strlen("null") + 1);//ignoring null + ','
		return new JsonNull();
	}
	return nullptr;
}

JsonValue* JsonValueFactory::parseValue(std::istream& ifs)
{
	Helper::skipWhitespaces(ifs);
	char ch = ifs.peek(); // Read the next character

	if (ch == '{') {
		return parseObject(ifs);
	}
	else if (ch == '[') {
		return parseArray(ifs);
	}
	else if (ch == '\"') {
		return jsonValueFactory(JsonValueType::MYSTRING, ifs);
	}
	else if (ch == '-' || Helper::isDigit(ch)) {
		return jsonValueFactory(JsonValueType::NUMBER, ifs);
	}
	else if (ch == 't' || ch == 'f') {
		return jsonValueFactory(JsonValueType::BOOL, ifs);
	}
	else if (ch == 'n') {
		return jsonValueFactory(JsonValueType::NULL_VALUE, ifs);
	}

	return nullptr;
}

JsonValue* JsonValueFactory::parseObject(std::istream& ifs)
{
	JsonObject* object = new JsonObject();
	ifs.ignore();//reading "{"

	while (!ifs.eof()) {
		if (ifs.peek() == '}') {
			ifs.ignore();
			break;
		}

		MyString key;
		parseKey(ifs, key);

		Helper::skipWhitespaces(ifs);
		JsonValue* value = parseValue(ifs);

		object->addElement(key, value);

		if (ifs.peek() == ',') {
			ifs.ignore();// Read the colon ','
		}

	}
	return object;
}

JsonValue* JsonValueFactory::parseArray(std::istream& ifs)
{
	JsonArray* array = new JsonArray();
	ifs.ignore();//reading [

	while (!ifs.eof()) {
		if (ifs.peek() == ']') {
			ifs.ignore();
			break;
		}

		JsonValue* value = parseValue(ifs);

		if (ifs.peek() == ',') {
			ifs.ignore();// Read the colon ','
		}

		if (value) {
			array->addValue(value);
		}

	}

	return array;
}

void JsonValueFactory::parseKey(std::istream& ifs, MyString& key)
{
	Helper::skipWhitespaces(ifs);
	char tempKey[1024];
	ifs.ignore();//reading '\"'
	ifs.getline(tempKey, 1024, '\"'); //key

	key = tempKey;//converting constructor

	ifs.ignore(); // Read the colon ':'
}

