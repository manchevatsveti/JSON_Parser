#include "JsonObject.h"
#include "JsonArray.h"
#include "../Factory/JsonValueFactory.h"
#include "../JsonFileHandler.h"
#include "../Utilities/Validation.h"
#include "../Utilities/Helper.h"
#include <iostream>
#include <sstream>

namespace {
	int findLastIndex(const MyString& filepath) {
		size_t size = filepath.length();

		for (int i = 0; i < size; i++) {
			if (filepath[i] == '/') {
				return i;
			}
		}
		return -1;
	}
}

void JsonObject::printArrayByKey(const JsonValue* value, const MyString& searchedKey) const
{
	const JsonArray* arr = static_cast<const JsonArray*>(value);

	size_t size = arr->getSize();

	for (int i = 0; i < size; i++) {
		if (arr->getElement(i)->getType() == JsonValueType::OBJECT) {
			const JsonObject* obj = static_cast<const JsonObject*>(arr->getElement(i));
			obj->printByKey(searchedKey);
		}
	}
}

const JsonValueType& JsonObject::getTypeByIndex(size_t index) const
{
	return elements[index].getValue()->getType();
}

void JsonObject::setValueFromPath(const MyString& filepath, JsonValue* newValue)
{
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) { //"name"
		if (getIndexByKey(filepath) == -1) {
			throw std::invalid_argument("This value does not exist!");
		}
		elements[getIndexByKey(filepath)].setValue(newValue);
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol - 1);
		temp->setValueFromPath(subFilepath,newValue);
	}
}

const JsonValue* JsonObject::getValueFromPath(const MyString& filepath)
{
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) { 
		if (getIndexByKey(filepath) == -1) {
			throw std::invalid_argument("This value does not exist!");
		}
		return elements[getIndexByKey(filepath)].getValue();
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol - 1);
		temp->getValueFromPath(subFilepath);
	}
}

const void JsonObject::writeToFile(const MyString& filename) const
{
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Could not open the output file");
	}
	print(file);

	file.close();
}

JsonObject::JsonObject() : JsonValue(JsonValueType::OBJECT){}


JsonValue* JsonObject::clone() const
{
	JsonValue* copy = new JsonObject(*this);
	return copy;
}

void JsonObject::addElement(const MyString& key,JsonValue* value)
{
	
	elements.pushBack(JsonNode(key, value));
}

void JsonObject::removeElement(size_t index)
{
	elements.popAt(index);
}

void JsonObject::print(std::ostream& ofs) const
{
	 ofs << "{" << std::endl;

	size_t size = elements.getSize();

	for (int i = 0; i < size; i++) {
		ofs << "\"" << elements[i].getKey() << "\":";
		elements[i].getValue()->print(ofs);

		if (i != size - 1) {
			ofs << ", " << std::endl;
		}
	}

	ofs << "}" << std::endl;
}

void JsonObject::printByKey(const MyString& searchedKey) const
{
	bool keyExists = false;
	size_t size = elements.getSize();
	for (int i = 0; i < size; i++) {
		if (elements[i].getKey() == searchedKey) {
			elements[i].getValue()->print(std::cout);
			std::cout << std::endl;
			keyExists = true;
		}
		if (elements[i].getValue()->getType() == JsonValueType::ARRAY) {
			printArrayByKey(elements[i].getValue(), searchedKey);
		}
	}

	if (!keyExists) {
		throw std::invalid_argument("This key does not exist");
	}
}

const JsonValue* JsonObject::getElement(int index) const
{
	if (index > elements.getSize()) {
		throw std::out_of_range("invalid index entered.");
	}
	return elements[index].getValue();

}

size_t JsonObject::getIndexByKey(const MyString& key)const
{
	size_t size = elements.getSize();

	for (int i = 0; i < size; i++) {
		if (elements[i].getKey() == key) {
			return i;
		}
	}
	return -1;//does not throw exception in case we want to check if the value does not exist
}

void JsonObject::setByKey(const MyString& filepath, const MyString& newValue)
{
	if (!Validation::isValidValue(Helper::removeQuotes(MyString(newValue)))) {
		throw std::invalid_argument("Invalid value!");
	}

	std::stringstream ss(newValue.c_str());
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) {
		if (getIndexByKey(filepath) == -1) {
			throw std::invalid_argument("This value does not exists!");
		}
		elements[getIndexByKey(filepath)].setValue(JsonValueFactory::parseValue(ss));
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol-1);
		temp->setByKey(subFilepath, newValue);
	}
}

void JsonObject::createByKey(const MyString& filepath, const MyString& newValue)
{
	std::stringstream ss(newValue.c_str());
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) {
		if (getIndexByKey(filepath) != -1 && getTypeByIndex(getIndexByKey(filepath)) != JsonValueType::ARRAY) {//we can create a value inside an array that already exists
			throw std::invalid_argument("This value already exists!");
		}
		else if (getIndexByKey(filepath) != -1 && getTypeByIndex(getIndexByKey(filepath)) == JsonValueType::ARRAY) {
			JsonArray* arr = static_cast<JsonArray*>(elements[getIndexByKey(filepath)].getValue());
			arr->addValue(JsonValueFactory::parseValue(ss));
		}else {
			elements.pushBack(JsonNode(filepath, JsonValueFactory::parseValue(ss)));
		}
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol - 1);
		temp->createByKey(subFilepath, newValue);
	}
}

void JsonObject::deleteBypath(const MyString& filepath)
{
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) {
		if (getIndexByKey(filepath) == -1) {
			throw std::invalid_argument("This value does not exist!");
		}

		removeElement(getIndexByKey(filepath));
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol - 1);
		temp->deleteBypath(subFilepath);
	}
}

void JsonObject::moveFromTo(const MyString& filePathFrom,const MyString& filePathTo)
{
	
	const JsonValue* valueFrom = getValueFromPath(filePathFrom);
	setValueFromPath(filePathTo, valueFrom->clone());

	deleteBypath(filePathFrom);
}

void JsonObject::saveAs(const MyString& filepath, const MyString& filename) 
{
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) {
		if (getIndexByKey(filepath) == -1) {
			throw std::invalid_argument("This value does not exist!");
		}
		
		if (getTypeByIndex(getIndexByKey(filepath)) == JsonValueType::OBJECT) {//we can only save objects to files
			JsonObject* newObj = static_cast<JsonObject*>(elements[getIndexByKey(filepath)].getValue());
			newObj->writeToFile(filename);
		}
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol - 1);
		temp->saveAs(subFilepath,filename);
	}
}

JsonNode& JsonObject::operator[](size_t index)
{
	return elements[index];
}

const JsonNode& JsonObject::operator[](size_t index) const
{
	return elements[index];
}
