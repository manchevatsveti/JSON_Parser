#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class SaveAs : public Command
{
	MyString filepath;

public:
	SaveAs(JsonObject* obj, const MyString& filepath);
	void execute() const override;
};
