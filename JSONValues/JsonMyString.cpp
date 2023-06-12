#include "JsonMyString.h"

JsonMyString::JsonMyString() : JsonValue(JsonValueType::MYSTRING)
{}


JsonMyString::JsonMyString(const MyString& value): JsonValue(JsonValueType::MYSTRING), value(value)
{}

JsonValue* JsonMyString::clone() const
{
	return new JsonMyString(*this);
}

void JsonMyString::print(std::ostream& ofs) const
{
	ofs <<"\""<< value << "\"";
}
