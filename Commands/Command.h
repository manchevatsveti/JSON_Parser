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
	PRINT,
	SEARCH_BY_KEY,
	SET,
	CREATE,
	DELETE,
	MOVE
};

class Command
{
protected:
	SharedPtr<JsonFileHandler>& fileHandler;

public:
	Command() = default;
	Command(SharedPtr<JsonFileHandler>& fileHandler);
	virtual void execute() = 0;

	virtual ~Command()=default;
	virtual Command* clone() const =0;
};

