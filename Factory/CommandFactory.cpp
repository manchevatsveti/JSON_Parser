#include "CommandFactory.h"


const CommandType& CommandFactory::getCommandType(const MyString& command)
{
    if (command == "open") {
        return CommandType::OPEN;
    }else if (command == "close") {
        return CommandType::CLOSE;
    }
    else if (command == "save") {
        return CommandType::SAVE;
    }
    else if (command == "saveas") {
        return CommandType::SAVE_AS;
    }
    else if (command == "help") {
        return CommandType::HELP;
    }
    else if (command == "exit") {
        return CommandType::EXIT;
    }
    else if (command == "print") {
        return CommandType::PRINT;
    }
    else if (command == "search") {
        return CommandType::SEARCH_BY_KEY;
    }
    else if (command == "set") {
        return CommandType::SET;
    }
    else if (command == "create") {
        return CommandType::CREATE;
    }
    else if (command == "delete") {
        return CommandType::DELETE;
    }
    else if (command == "move") {
        return CommandType::MOVE;
    }
}

Command* CommandFactory::getCommand()
{
    char command[1024];
    std::cin>>command;//reading till first space
    char buff[1024];
    std::cin.getline(buff, 1024, '\n');
    std::stringstream ss(buff);

    static SharedPtr<JsonFileHandler> fileHandler = new JsonFileHandler();
    
    return commandFactory(getCommandType(command), ss, fileHandler);
  
    return nullptr;//validation
}

Command* CommandFactory::commandFactory( CommandType type, std::stringstream& ss, SharedPtr<JsonFileHandler>& fileHandler)
{
    switch (type) {
    case CommandType::OPEN: {
        MyString filename;
        Helper::readData(ss, filename);

       return new Open(fileHandler,filename);
    }
    case CommandType::CLOSE: {
        return new Close(fileHandler);
    }case CommandType::SAVE: {
        MyString filepath;
        Helper::readData(ss, filepath);

        return new Save(fileHandler,filepath);
    }
    case CommandType::SAVE_AS: {
        MyString filename;
        Helper::readData(ss, filename);
        MyString filepath;
        Helper::readData(ss, filepath);

        return new SaveAs(fileHandler,filename, filepath);
    }
    case CommandType::EXIT: {
        return new Exit(fileHandler);
    }
    case CommandType::PRINT: {
        return new Print(fileHandler);
    }
    case CommandType::SEARCH_BY_KEY: {
        MyString searchedKey;
        Helper::readData(ss, searchedKey);
        
        return new SearchByKey(fileHandler, searchedKey);
    }
    case CommandType::SET: {
        MyString filepath;
        Helper::readData(ss, filepath);
        MyString newValue;
        Helper::readData(ss, newValue);

        return new Set(fileHandler, filepath,newValue);
    }
    case CommandType::CREATE: {
        MyString filepath;
        Helper::readData(ss, filepath);
        MyString newValue;
        Helper::readValue(ss, newValue);

      return new Create(fileHandler, filepath, newValue);
    }
    case CommandType::DELETE: {
        MyString filepath;
        Helper::readData(ss, filepath);

        return new Delete(fileHandler, filepath);
    }
    case CommandType::MOVE: {
        MyString filepathFrom;
        Helper::readData(ss, filepathFrom);
        MyString filepathTo;
        Helper::readData(ss, filepathTo);

        return new Move(fileHandler, filepathFrom, filepathTo);
    }
    }
    return nullptr;
}
