#include "Command.h"
#include "../JSONValues/JsonValue.h"

Command::Command():obj(nullptr)
{
}

Command::Command(const JsonValue* obj) : obj(obj)
{
}
