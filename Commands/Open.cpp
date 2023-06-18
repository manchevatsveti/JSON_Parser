#include "Open.h"
#include "../JsonFileHandler.h"

Open::Open(SharedPtr<JsonFileHandler>& fileHandler,const MyString& filename) :Command(fileHandler),filename(filename) {}

void Open::execute()
{
	fileHandler->open(filename);
}
