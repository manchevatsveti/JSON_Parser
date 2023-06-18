#pragma once
#include <fstream>
#include "StringView.h"

class Validation
{
public:
	static bool isNumber(std::istream& ifs);

	static bool isValidValue(const StringView& value);

	static bool isValidObject(const StringView& fileContent);
	static bool isValidNode(const StringView& nodeContent);
	static bool isValidString(const StringView& str);
	static bool isValidArray(const StringView& value);
	static bool isValidBool(const StringView& value);
	static bool isValidNull(const StringView& value);
	static bool isValidNumber(const StringView& value);
};

