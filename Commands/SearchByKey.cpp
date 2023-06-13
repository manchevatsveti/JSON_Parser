#include "SearchByKey.h"
#include "../JSONValues/JsonObject.h"

SearchByKey::SearchByKey(JsonObject* obj, const MyString& searchedKey):Command(obj),searchedKey(searchedKey)
{}

void SearchByKey::execute() const
{
	obj->printByKey(searchedKey);

}

