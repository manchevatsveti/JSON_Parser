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

void JsonArray::removeValue(size_t index)
{
	values.popAt(index);
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
	ofs << "["<<std::endl;
	size_t size = values.getSize();

	for (int i = 0; i < size; i++) {
		values[i]->print(ofs);

		if (i != size - 1) {
			ofs << ", " << std::endl;
		}
	}
	ofs << "]" << std::endl;
}

size_t JsonArray::getSize() const
{
	return values.getSize();
}

const JsonValue* JsonArray::getElement(size_t index) const
{
	if (index >= values.getSize()) {
		throw std::out_of_range("Invalid index.");
	}
	return values[index].operator->();////NE!!
}

