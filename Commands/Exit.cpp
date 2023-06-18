#include "Exit.h"

static const char* EXIT_MSG = "The program was terminated.";

Exit::Exit(SharedPtr<JsonFileHandler>& fileHandler):Command(fileHandler){}

void Exit::execute()
{
	fileHandler->close();
	throw exit_exc();
}

Command* Exit::clone() const
{
	return new Exit(*this);
}

char const* exit_exc::what() const
{
	return EXIT_MSG;
}
