#include "Save.h"

Save::Save(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filepath) :Command(fileHandler) {}

void Save::execute()
{
	fileHandler->save(filepath);
}
