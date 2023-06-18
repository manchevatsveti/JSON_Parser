#include "Delete.h"

Delete::Delete(SharedPtr<JsonFileHandler> fileHandler, const MyString& filepath) :Command(fileHandler), filepath(filepath){}

void Delete::execute()
{
	fileHandler->deleteBypath(filepath);
}
