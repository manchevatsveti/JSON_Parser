#include "SaveAs.h"

SaveAs::SaveAs(SharedPtr<JsonFileHandler>& fileHandler, const MyString& filename, const MyString& filepath):Command(fileHandler),filepath(filepath), filename(filename) {}

void SaveAs::execute()
{
	fileHandler->saveAs(filepath, filename);
}
