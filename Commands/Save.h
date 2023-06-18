#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Save : public Command
{
	MyString filepath;
	MyString filename;

public:
	Save(SharedPtr<JsonFileHandler>& fileHandler,const MyString& filepath);
	void execute() override;
	Command* clone() const override;
};