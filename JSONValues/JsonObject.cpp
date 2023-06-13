#include "JsonObject.h"
#include "JsonArray.h"
#include "../Factory/JsonValueFactory.h"
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

void JsonObject::print(std::ostream& ofs) const
{
	 ofs << "{";

	size_t size = elements.getSize();

	for (int i = 0; i < size; i++) {
		ofs << "\"" << elements[i].getKey() << "\":";
		elements[i].getValue()->print(ofs);

		if (i != size - 1) {
			ofs << ", ";
		}
	}

	ofs << "}";
}

size_t JsonObject::getNodesCount() const
{
	return elements.getSize();
}

void JsonObject::printByKey(const MyString& searchedKey) const
{
	size_t size = elements.getSize();
	for (int i = 0; i < size; i++) {
		if (elements[i].getKey() == searchedKey) {
			elements[i].getValue()->print(std::cout);
			std::cout << std::endl;
		}
		if (elements[i].getValue()->getType() == JsonValueType::ARRAY) {
			printArrayByKey(elements[i].getValue(), searchedKey);
		}
	}
}

const JsonValue* JsonObject::getElement(int index) const
{
	if (index > getNodesCount()) {
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
	throw std::logic_error("This key does not exist!");
}

void JsonObject::setByKey(const MyString& filepath, const MyString& newValue)
{
	std::stringstream ss(newValue.c_str());
	int indexSlashSymbol = findLastIndex(filepath);
	if (indexSlashSymbol == -1) {
		elements[getIndexByKey(filepath)].setValue(JsonValueFactory::parseValue(ss));
	}
	else {
		MyString rootPath = filepath.substr(0, indexSlashSymbol);
		JsonObject* temp = dynamic_cast<JsonObject*>(elements[getIndexByKey(rootPath)].getValue());
		MyString subFilepath = filepath.substr(indexSlashSymbol + 1, filepath.length() - indexSlashSymbol-1);
		temp->setByKey(subFilepath, newValue);
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
