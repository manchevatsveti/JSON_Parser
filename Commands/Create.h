#pragma once
#pragma once
#include "../Commands/Command.h"

class Create : public Command
{
	MyString filepath;
	MyString newValue;

public:
	Create(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filepath, const MyString& newValue);
	void execute() override;
	Command* clone() const override;
};

