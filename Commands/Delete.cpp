#include "Delete.h"

Delete::Delete(JsonObject* obj, const MyString& filepath) :Command(obj), filepath(filepath){}

void Delete::execute() const
{
	obj->deleteBypath(filepath);
}
