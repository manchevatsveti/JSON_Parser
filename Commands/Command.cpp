#include "Command.h"
#include "../JSONValues/JsonValue.h"

Command::Command():obj(nullptr)
{}

Command::Command(JsonObject* obj) : obj(obj)
{}
