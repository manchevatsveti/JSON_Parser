#include "Close.h"

Close::Close(SharedPtr<JsonFileHandler>& fileHandler):Command(fileHandler){}

void Close::execute()
{
	fileHandler->close();
}
