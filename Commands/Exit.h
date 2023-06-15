#pragma once
#include "Command.h"
#include "../JSONValues/JsonValue.h"
#include "../Utilities/MyString.h"
#include <sstream>

class Exit : public Command
{
public:
	Exit() = default;
	void execute() const override;
};