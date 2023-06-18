#include "JsonFileHandler.h"
#include "Factory/JsonValueFactory.h"
#include <fstream>

static MyString CLOSED_FILE_MSG = "The file was closed. Please open a new one or exit the program!";

JsonFileHandler::JsonFileHandler():_filename(),obj(nullptr){}

JsonObject* JsonFileHandler::readJsonFile(const MyString& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the output file");
    }

    JsonObject* rootValue = dynamic_cast<JsonObject*>(JsonValueFactory::parseValue(file));

    file.close();
    return rootValue;
}

void JsonFileHandler::open(const MyString& filename)
{
    obj = readJsonFile(filename);
    _filename = filename;
}

void JsonFileHandler::close()
{
    obj = nullptr;
    std::cout << CLOSED_FILE_MSG << std::endl;
}

void JsonFileHandler::print(std::ostream& ofs) const
{
    obj->print(std::cout);
}

void JsonFileHandler::printByKey(const MyString& searchedKey) const
{
    obj->printByKey(searchedKey);
}

void JsonFileHandler::setByKey(const MyString& filepath, const MyString& newValue)
{
    obj->setByKey(filepath,newValue);
}

void JsonFileHandler::createByKey(const MyString& filepath, const MyString& newValue)
{
    obj->createByKey(filepath, newValue);
}

void JsonFileHandler::deleteBypath(const MyString& filepath)
{
    obj->deleteBypath(filepath);
}

void JsonFileHandler::moveFromTo(const MyString& filePathFrom, const MyString& filePathTo)
{
    obj->moveFromTo(filePathFrom, filePathTo);
}

void JsonFileHandler::saveAs(const MyString& filepath, const MyString& filename)
{
    obj->saveAs(filepath, filename);
}

void JsonFileHandler::save(const MyString& filepath)
{
    obj->saveAs(filepath, _filename);
}

JsonFileHandler::~JsonFileHandler()
{
    delete obj;
}
