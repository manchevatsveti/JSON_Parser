#include "JsonObject.h"
#include <iostream>

JsonObject::JsonObject() : JsonValue(JsonValueType::OBJECT)
{}


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
		elements[i].getValue()->printByKey(searchedKey);
	}
}

const JsonValue* JsonObject::getElement(int index) const
{
	if (index > getNodesCount()) {
		throw std::out_of_range("invalid index entered.");
	}
	return elements[index].getValue();

}
