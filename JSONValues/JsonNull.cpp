#include "JsonNull.h"
#include <iostream>

JsonNull::JsonNull() : JsonValue(JsonValueType::NULL_VALUE)
{}


JsonValue* JsonNull::clone() const
{
    return new JsonNull(*this);
}

void JsonNull::print(std::ostream& ofs) const
{
    ofs << "null";
}
