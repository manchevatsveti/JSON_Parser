#include <iostream>
#include "JsonFileHandler.h"
#include "JSONValues/JsonObject.h"
#include "Factory/CommandFactory.h"

int main() {
	JsonFileHandler jh;
	JsonObject* obj = dynamic_cast<JsonObject*>(jh.readJsonFile("json_2.txt"));

	try {
		CommandFactory::getCommand(obj)->execute();
	}
	catch (int& i) {

	}

	try {
		CommandFactory::getCommand(obj)->execute();
	}
	catch (int& i) {

	}
}