#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Close : public Command
{
public:
	Close(SharedPtr<JsonFileHandler>& fileHandler);
	void execute() override;
	Command* clone() const override;
};