#pragma once
#include "JsonValue.h"

class JsonNumber : public JsonValue
{
	double value;
public:
	JsonNumber() ;
	JsonNumber(double value);
	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;
	void writeToFile(std::ostream& ofs) const override;
};