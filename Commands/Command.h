#pragma once
#include "../JsonFileHandler.h"
#include "../Utilities/SharedPtr.hpp"

enum class CommandType
{
	OPEN,
	CLOSE,
	SAVE,
	SAVE_AS,
	HELP,
	EXIT,
	VALIDATE,
	PRINT,
	SEARCH_BY_KEY
};

class Command
{
protected:
	SharedPtr<JsonFileHandler>& fileHandler;

public:
	Command() = default;//???
	Command(SharedPtr<JsonFileHandler>& fileHandler);
	virtual void execute() = 0;
};

