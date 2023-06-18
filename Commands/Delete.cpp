#include "Delete.h"

Delete::Delete(SharedPtr<JsonFileHandler> fileHandler, const MyString& filepath) :Command(fileHandler), filepath(filepath){}

void Delete::execute()
{
	fileHandler->deleteBypath(filepath);
}

Command* Delete::clone() const
{
	return new Delete(*this);
}
