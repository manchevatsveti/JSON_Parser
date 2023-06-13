#include "Create.h"

Create::Create(JsonObject* obj, const MyString& filepath, const MyString& newValue) :Command(obj), filepath(filepath), newValue(newValue) {}

void Create::execute() const
{
	obj->createByKey(filepath, newValue);
}

