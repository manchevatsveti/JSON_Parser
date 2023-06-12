#include "JsonValueFactory.h"
#include "../JSONValues/JsonBool.h"
#include "../JSONValues/JsonNumber.h"
#include "../JSONValues/JsonMyString.h"
#include "../JSONValues/JsonArray.h"
#include "../JSONValues/JsonObject.h"
#include "../JSONValues/JsonNull.h"

namespace {
	bool isDigit(const char ch) {
		if (ch < '0' || ch>'9') {
			return false;
		}
		return true;
	}

	void skipWhitespaces(std::ifstream& ifs) {

		while (ifs.peek() == ' ') {
			ifs.ignore();
		}
	}
}

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

JsonValue* JsonValueFactory::jsonValueFactory(JsonValueType type, std::ifstream& ifs)
{
	switch (type)
	{
	case JsonValueType::NUMBER:
	{
		double value;
		ifs >> value;
		return new JsonNumber(value);

	}
	case JsonValueType::BOOL: //validation
	{
		char ch = ifs.peek();
		bool value;
		if (ch == 't') {
			value = true;
			//ifs.ignore(4);
		}
		else {
			value = false;
			//ifs.ignore(5);
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
		//ifs.ignore(4);
		return new JsonNull();
	}
	return nullptr;
}

JsonValue* JsonValueFactory::parseValue(std::ifstream& ifs)
{
	skipWhitespaces(ifs);
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
	else if (ch == '-' || isDigit(ch)) {
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

JsonValue* JsonValueFactory::parseObject(std::ifstream& ifs)
{
	JsonObject* object = new JsonObject();//casting?
	ifs.ignore();//reading "{"

	while (!ifs.eof()) {
		if (ifs.peek() == '}') {
			ifs.ignore();
			break;
		}

		MyString key;
		parseKey(ifs, key);

		skipWhitespaces(ifs);
		JsonValue* value = parseValue(ifs);//try catch

		object->addElement(key, value);

		if (ifs.peek() == ',') {
			ifs.ignore();// Read the colon ','
		}

	}
	return object;
}

JsonValue* JsonValueFactory::parseArray(std::ifstream& ifs)
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

void JsonValueFactory::parseKey(std::ifstream& ifs, MyString& key)
{
	skipWhitespaces(ifs);
	char tempKey[1024];
	ifs.ignore();//reading '\"'
	ifs.getline(tempKey, 1024, '\"'); //key

	key = tempKey;//converting constructor

	ifs.ignore(); // Read the colon ':'
}

