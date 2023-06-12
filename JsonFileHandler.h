#pragma once
#include "JSONValues/JsonValue.h"
#include "Utilities/MyString.h"

class JsonFileHandler
{
public:
	static JsonValue* readJsonFile(const MyString& filename);
	
};

