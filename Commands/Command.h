#pragma once
#include "../JSONValues/JsonObject.h"

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
	JsonObject* obj;
public:
	Command();
	Command(JsonObject* obj);
	virtual void execute() const = 0;
};

