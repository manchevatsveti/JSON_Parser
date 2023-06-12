#include "JsonArray.h"
#include "../Factory/JsonValueFactory.h"

JsonArray::JsonArray() : JsonValue(JsonValueType::ARRAY)
{}

void JsonArray::addValue(JsonValueType valuesType)
{
	values.pushBack(JsonValueFactory::jsonValueFactory(valuesType));
}

void JsonArray::addValue(JsonValue* value)
{
	values.pushBack(value);
}

JsonValueType JsonArray::getTypeByIndex(unsigned index) const
{
	return values[index]->getType();
}

JsonValue* JsonArray::clone() const
{
	return new JsonArray(*this);
}

void JsonArray::print(std::ostream& ofs) const
{
	ofs << "[";
	size_t size = values.getSize();

	for (int i = 0; i < size; i++) {
		values[i]->print(ofs);

		if (i != size - 1) {
			ofs << ", ";
		}
	}
	ofs << "]";
}

void JsonArray::printByKey(const MyString& searchedKey) const
{
	size_t size = values.getSize();

	for (int i = 0; i < size; i++) {
		values[i]->printByKey(searchedKey);
	}
}
