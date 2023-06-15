#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Open : public Command
{
	MyString filename;
	JsonObject*& obj;

public:
	Open(JsonObject*& obj, const MyString& filename);
	void execute() const override;
};