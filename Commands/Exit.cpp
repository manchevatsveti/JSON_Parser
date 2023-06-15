#include "Exit.h"

static MyString EXIT_MSG = "The program was terminated.";

void Exit::execute() const
{
	std::cout << EXIT_MSG;
	throw std::exception("end");
}
