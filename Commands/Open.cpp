#include "Open.h"
#include "../JsonFileHandler.h"

Open::Open(SharedPtr<JsonFileHandler>& fileHandler,const MyString& filename) :Command(fileHandler),filename(filename) {}

void Open::execute()
{
	try {
		fileHandler->open(filename);
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what();
	}
	
}

Command* Open::clone() const
{
	return new Open(*this);
}
