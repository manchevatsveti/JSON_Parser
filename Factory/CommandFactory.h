#pragma once
#include "../Commands/Command.h"
#include "../JSONValues/JsonObject.h"
#include "../Utilities/MyString.h"
#include "../Commands/Print.h"
#include "../Commands/SearchByKey.h"
#include "../Commands/Set.h"
#include "../Commands/Create.h"
#include "../Commands/Delete.h"
#include "../Commands/Move.h"
#include "../Commands/Open.h"
#include "../Commands/Close.h"
#include "../Commands/Exit.h"
#include "../Commands/SaveAs.h"
#include "../Commands/Save.h"
#include "../JsonFileHandler.h"
#include "../Utilities/SharedPtr.hpp"
#include "../Utilities/Helper.h"
#include <sstream>

class CommandFactory
{
	static const CommandType& getCommandType(const MyString& command);

public:
	static Command* getCommand();
	static Command* commandFactory(CommandType type,std::stringstream& ss, SharedPtr<JsonFileHandler>& fileHandler);
};

