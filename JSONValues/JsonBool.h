#pragma once
#include "JsonValue.h"
class JsonBool : public JsonValue
{
	bool value;
public:
	JsonBool();
	JsonBool(bool value);
	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;
	void writeToFile(std::ostream& ofs) const override;

};

