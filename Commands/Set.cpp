#include "Set.h"

Set::Set(JsonObject* obj, const MyString& filepath, const MyString& newValue):Command(obj),filepath(filepath),newValue(newValue){}

void Set::execute() const
{
	obj->setByKey(filepath, newValue);
	
}
