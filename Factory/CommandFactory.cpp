#include "CommandFactory.h"
#include "../Utilities/MyString.h"
#include "../Commands/Print.h"
#include "../Commands/SearchByKey.h"
#include "../Commands/Set.h"
#include "../Commands/Create.h"
#include "../Commands/Delete.h"
#include "../Commands/Move.h"
#include "../Commands/Open.h"
#include "../Commands/Close.h"
#include "../Commands/Exit.h"
#include "../Commands/SaveAs.h"
#include "../JsonFileHandler.h"
#include "../Utilities/SharedPtr.hpp"
#include <sstream>

const size_t COMMANDS_COUNT = 13;
static const MyString commands[COMMANDS_COUNT] = { "open","close","save","saveas","help","exit",
                                                 "validate","print","search","set","create","delete","move" };


namespace {
    bool isDigit(const char ch) {
        if (ch < '0' || ch>'9') {
            return false;
        }
        return true;
    }

    void skipWhitespaces(std::stringstream& ss) {

        while (ss.peek() == ' ') {
            ss.ignore();
        }
    }

    void removeQuotes(MyString& str) {
        str = str.substr(1, str.length() - 2);
    }

    void readValue(std::stringstream& ss, MyString& str) {
        skipWhitespaces(ss);
        char searchedKey[1024];
        ss.getline(searchedKey, 1024, '\t');
        str = std::move(searchedKey);//move op= of MyString
        removeQuotes(str);
    }

    void readData(std::stringstream& ss, MyString& str) {
        skipWhitespaces(ss);
        ss.ignore();//reading '\"'
        char searchedKey[1024];
        ss.getline(searchedKey, 1024, '\"');
        str = std::move(searchedKey);//move op= of MyString
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
    
    for (int i = 0; i < COMMANDS_COUNT; i++) {
        if (command == commands[i]) {
            return commandFactory(i + 1, ss, fileHandler);
        }
    }

    return nullptr;
}

Command* CommandFactory::commandFactory(int typeNumber, std::stringstream& ss, SharedPtr<JsonFileHandler>& fileHandler)
{
    switch (typeNumber) {
    case 1: {
        MyString filename;
        readData(ss, filename);

       return new Open(fileHandler,filename);
    }
    case 2: {
        return new Close(fileHandler);
    }case 4: {
        MyString filename;
        readData(ss, filename);
        MyString filepath;
        readData(ss, filepath);

        return new SaveAs(fileHandler,filename, filepath);
    }
    case 6: {
        return new Exit(fileHandler);
    }
    case 8: {
        return new Print(fileHandler);
    }
    case 9: {
        MyString searchedKey;
        readData(ss, searchedKey);
        
        return new SearchByKey(fileHandler, searchedKey);
    }
    case 10: {
        MyString filepath;
        readData(ss, filepath);
        MyString newValue;
        readData(ss, newValue);

        return new Set(fileHandler, filepath,newValue);
    }
    case 11: {
        MyString filepath;
        readData(ss, filepath);
        MyString newValue;
        readValue(ss, newValue);

      return new Create(fileHandler, filepath, newValue);
    }
    case 12: {
        MyString filepath;
        readData(ss, filepath);

        return new Delete(fileHandler, filepath);
    }
    case 13: {
        MyString filepathFrom;
        readData(ss, filepathFrom);
        MyString filepathTo;
        readData(ss, filepathTo);

        return new Move(fileHandler, filepathFrom, filepathTo);
    }
    }
    return nullptr;
}
