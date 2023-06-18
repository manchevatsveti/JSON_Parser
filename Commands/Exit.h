#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <exception>
#include <sstream>

class exit_exc : std::exception {
public:
	char const* what() const;
};

class Exit : public Command
{
public:
	Exit(SharedPtr<JsonFileHandler>& fileHandler) ;
	void execute() override;
};