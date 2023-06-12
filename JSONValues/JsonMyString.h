#pragma once
#include "JsonValue.h"
#include "../Utilities/MyString.h"

class JsonMyString : public JsonValue
{
	MyString value;

public:
	JsonMyString();
	JsonMyString(const MyString& value);
	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;
};

