#include "JsonFileHandler.h"
#include "Factory/JsonValueFactory.h"
#include <fstream>


JsonValue* JsonFileHandler::readJsonFile(const MyString& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the output file");
    }

    JsonValue* rootValue = JsonValueFactory::parseValue(file);

    file.close();
    return rootValue;
}
