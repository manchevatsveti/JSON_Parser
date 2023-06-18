#include "Print.h"

Print::Print(SharedPtr<JsonFileHandler>& fileHandler) :Command(fileHandler) {}

void Print::execute()
{
	fileHandler->print(std::cout);
}

Command* Print::clone() const
{
	return new Print(*this);
}
