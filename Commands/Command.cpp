#include "Command.h"
#include "../JSONValues/JsonValue.h"

Command::Command(SharedPtr<JsonFileHandler>& fileHandler) : fileHandler(fileHandler)
{}
