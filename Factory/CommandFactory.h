#pragma once
#include "../Commands/Command.h"
#include "../JSONValues/JsonObject.h"
#include <sstream>

class CommandFactory
{

public:
	static Command* getCommand();
	static Command* commandFactory(int typeNumber,std::stringstream& ss, SharedPtr<JsonFileHandler>& fileHandler);
};

