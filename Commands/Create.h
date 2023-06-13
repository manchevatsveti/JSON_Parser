#pragma once
#pragma once
#include "../Commands/Command.h"

class Create : public Command
{
	MyString filepath;
	MyString newValue;
public:
	Create(JsonObject* obj, const MyString& filepath, const MyString& newValue);
	void execute() const override;
};

