#include "Close.h"

static MyString CLOSED_FILE_MSG = "The file was closed. Please open a new one or exit the program!";

Close::Close(JsonObject*& obj):obj(obj){}

void Close::execute() const
{
	obj = nullptr;
	std::cout << CLOSED_FILE_MSG;
}
