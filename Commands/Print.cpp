#include "Print.h"

Print::Print(SharedPtr<JsonFileHandler>& fileHandler) :Command(fileHandler) {}

void Print::execute()
{
	fileHandler->print(std::cout);
}
