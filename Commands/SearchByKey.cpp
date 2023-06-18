#include "SearchByKey.h"
#include "../JSONValues/JsonObject.h"

SearchByKey::SearchByKey(SharedPtr<JsonFileHandler>& fileHandler, const MyString& searchedKey):Command(fileHandler),searchedKey(searchedKey)
{}

void SearchByKey::execute()
{
	fileHandler->printByKey(searchedKey);

}

