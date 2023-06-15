#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Close : public Command
{
	JsonObject*& obj;
public:
	Close(JsonObject*& obj);
	void execute() const override;
};