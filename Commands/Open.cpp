#include "Open.h"
#include "../JsonFileHandler.h"

Open::Open(JsonObject*& obj,const MyString& filename) :obj(obj),filename(filename) {}

void Open::execute() const
{
	JsonFileHandler jh;
	obj = dynamic_cast<JsonObject*>(jh.readJsonFile(filename));
}
