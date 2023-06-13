#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Set : public Command
{
	MyString filepath;
	MyString newValue;
public:
	Set(JsonObject* obj, const MyString& filepath,const MyString& newValue);
	void execute() const override;
};