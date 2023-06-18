#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class SearchByKey : public Command
{
	MyString searchedKey;

public: 
	SearchByKey(SharedPtr<JsonFileHandler>& fileHandler,const MyString& searchedKey);
	void execute() override;
	Command* clone() const override;
};

