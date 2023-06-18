#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Delete : public Command
{
	MyString filepath;

public:
	Delete(SharedPtr<JsonFileHandler> fileHandler, const MyString& filepath);
	void execute() override;
};