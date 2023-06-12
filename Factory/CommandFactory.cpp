#include "CommandFactory.h"
#include "../Utilities/MyString.h"
#include "../Commands/Print.h"
#include "../Commands/SearchByKey.h"
#include <sstream>

const size_t COMMANDS_COUNT = 13;
static const MyString commands[COMMANDS_COUNT] = { "open","close","save","saveas","help","exit","validate","print","search","set","create","delete","move" };

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
}

Command* CommandFactory::getCommand(const JsonObject* obj)
{
    char command[1024];
    std::cin>>command;//reading till first space
    char buff[1024];
    std::cin.getline(buff, 1024, '\n');
    std::stringstream ss(buff);

    for (int i = 0; i < COMMANDS_COUNT; i++) {
        if (command == commands[i]) {
            return commandFactory(i + 1, ss,obj);
        }
    }
    return nullptr;
}

Command* CommandFactory::commandFactory(int typeNumber, std::stringstream& ss,const JsonObject* obj)
{
    switch (typeNumber) {
    case 8: {
        return new Print(obj);
    }
    case 9: {
        skipWhitespaces(ss);
        ss.ignore();//reading '\"'
        char key[1024];
        ss.getline(key, 1024, '\"');
        return new SearchByKey(obj,key);
    }
    }
    return nullptr;
}
