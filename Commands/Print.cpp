#include "Print.h"

Print::Print(JsonObject* obj) :Command(obj) {}

void Print::execute() const
{
	obj->print(std::cout);
}
