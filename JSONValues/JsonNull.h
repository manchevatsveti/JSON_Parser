#pragma once
#include "JsonValue.h"

class JsonNull : public JsonValue
{
public:
	JsonNull();
	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;
};

