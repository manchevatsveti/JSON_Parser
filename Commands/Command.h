#pragma once
#include "../JSONValues/JsonValue.h"

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
	const JsonValue* obj;
public:
	Command();
	Command(const JsonValue* obj);
	virtual void execute() const = 0;
};

