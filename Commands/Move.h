#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Move : public Command
{
	MyString filePathFrom;
	MyString filePathTo;

public:
	Move(JsonObject* obj, const MyString& filePathFrom, const MyString& filePathTo);
	void execute() const override;
};
