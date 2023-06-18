#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Open : public Command
{
	MyString filename;

public:
	Open(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filename);
	void execute() override;
	Command* clone() const override;
};