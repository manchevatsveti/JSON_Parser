#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"

class Print : public Command
{
public:
	Print(SharedPtr<JsonFileHandler>& fileHandler);
	void execute() override;
	Command* clone() const override;
};
