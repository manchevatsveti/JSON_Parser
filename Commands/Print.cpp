#include "Print.h"

Print::Print(const JsonValue* obj):Command(obj){}

void Print::execute() const
{
	obj->print(std::cout);
}
