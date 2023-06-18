#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class SaveAs : public Command
{
	MyString filepath;
	MyString filename;

public:
	SaveAs(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filename, const MyString& filepath);
	void execute() override;
};
