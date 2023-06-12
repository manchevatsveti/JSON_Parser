#pragma once
#include "../Commands/Command.h"
#include "../JSONValues/JsonObject.h"
#include <sstream>

class CommandFactory
{
public:
	static Command* getCommand(const JsonObject* obj);
	static Command* commandFactory(int typeNumber,std::stringstream& ss,const JsonObject* obj);
};

