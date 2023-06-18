#include "Create.h"

Create::Create(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filepath, const MyString& newValue) :Command(fileHandler), filepath(filepath), newValue(newValue) {}

void Create::execute()
{
	fileHandler->createByKey(filepath, newValue);
}

