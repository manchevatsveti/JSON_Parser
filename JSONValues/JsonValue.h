#pragma once
#include <iostream>
#include <fstream>
#include "../Utilities/MyString.h"

enum class JsonValueType
{
	NUMBER,
	BOOL,
	MYSTRING,
	ARRAY,
	OBJECT,
	NULL_VALUE
};

class JsonValue
{
	JsonValueType type;
public:
	JsonValue();
	JsonValue(JsonValueType);
	virtual JsonValue* clone() const = 0;
	virtual ~JsonValue() = default;

	JsonValueType getType() const;

	virtual void print(std::ostream& ofs) const = 0;
	virtual void printByKey(const MyString& searchedKey)const;
	//virtual void set(std::stringstream& path, const MyString& name);
};

