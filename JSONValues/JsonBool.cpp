#include "JsonBool.h"
#include <iostream>

JsonBool::JsonBool() : JsonValue(JsonValueType::BOOL)
{}


JsonBool::JsonBool(bool value):value(value){}

JsonValue* JsonBool::clone() const
{
    return new JsonBool(*this);
}

void JsonBool::print(std::ostream& ofs) const
{
    if (value) {
        ofs << "true";
    }
    else {
        ofs << "false";
    }
}

void JsonBool::writeToFile(std::ostream& ofs) const
{
    print(ofs);
}
