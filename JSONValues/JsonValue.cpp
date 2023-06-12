#include "JsonValue.h"

JsonValue::JsonValue() : type(JsonValueType::NULL_VALUE){}

JsonValue::JsonValue(JsonValueType type) : type(type){}

JsonValueType JsonValue::getType() const
{
	return type;
}

void JsonValue::printByKey(const MyString& searchedKey) const
{}
