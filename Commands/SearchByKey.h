#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class SearchByKey : public Command
{
	MyString searchedKey;

public: 
	SearchByKey(JsonObject* obj,const MyString& searchedKey);
	void execute() const override;
};

