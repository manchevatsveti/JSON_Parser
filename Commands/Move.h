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
	Move(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filePathFrom, const MyString& filePathTo);
	void execute() override;
};
