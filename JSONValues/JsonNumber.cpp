#include "JsonNumber.h"

JsonNumber::JsonNumber() : JsonValue(JsonValueType::NUMBER)
{}


JsonNumber::JsonNumber(double value):value(value)
{}

JsonValue* JsonNumber::clone() const
{
	return new JsonNumber(*this);
}

void JsonNumber::print(std::ostream& ofs) const
{
	ofs << value;
}
