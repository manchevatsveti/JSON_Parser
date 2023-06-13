#pragma once
#include "JsonValue.h"
#include "../Utilities/Vector.hpp"
#include "../Utilities/SharedPtr.hpp"

class JsonArray : public JsonValue
{
	///Iterator for JsonArray????
	Vector<SharedPtr<JsonValue>> values;

public:
	JsonArray();

	void addValue(JsonValueType animalType);
	void addValue(JsonValue* value);

	JsonValueType getTypeByIndex(unsigned index) const;

	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;

	size_t getSize() const;
	const JsonValue* getElement(size_t index) const;
};

