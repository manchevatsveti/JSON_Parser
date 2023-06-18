#include "Move.h"

Move::Move(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filePathFrom, const MyString& filePathTo):Command(fileHandler),filePathFrom(filePathFrom), filePathTo(filePathTo){}

void Move::execute()
{
	fileHandler->moveFromTo(filePathFrom, filePathTo);
}

Command* Move::clone() const
{
	return new Move(*this);
}
