#include "Set.h"

Set::Set(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filepath, const MyString& newValue):Command(fileHandler),filepath(filepath),newValue(newValue){}

void Set::execute()
{
	fileHandler->setByKey(filepath, newValue);
	
}

Command* Set::clone() const
{
	return new Set(*this);
}
