#pragma once
#include "../Commands/Command.h"
#include "../JSONValues/JsonObject.h"
#include <sstream>

class CommandFactory
{
public:
	static Command* getCommand(JsonObject* obj);
	static Command* commandFactory(int typeNumber,std::stringstream& ss,JsonObject* obj);
};

