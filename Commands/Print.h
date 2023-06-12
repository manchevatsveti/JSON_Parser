#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"

class Print : public Command
{
public:
	Print(const JsonValue* obj);
	void execute() const override;
};

