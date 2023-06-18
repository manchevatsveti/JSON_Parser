#include "Exit.h"

static MyString EXIT_MSG = "The program was terminated.";

Exit::Exit(SharedPtr<JsonFileHandler>& fileHandler):Command(fileHandler){}

void Exit::execute()
{
	fileHandler->close();
	std::cout << EXIT_MSG;
	throw std::exception("end");
}
