#include "Move.h"

Move::Move(JsonObject* obj, const MyString& filePathFrom, const MyString& filePathTo):Command(obj),filePathFrom(filePathFrom), filePathTo(filePathTo){}

void Move::execute() const
{
	obj->moveFromTo(filePathFrom, filePathTo);
}
