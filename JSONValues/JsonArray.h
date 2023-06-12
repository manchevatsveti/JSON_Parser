#pragma once
#include "JsonValue.h"
#include "../Utilities/Vector.hpp"
#include "../Utilities/SharedPtr.hpp"

class JsonArray : public JsonValue
{
	Vector<SharedPtr<JsonValue>> values;

public:
	JsonArray();

	void addValue(JsonValueType animalType);
	void addValue(JsonValue* value);

	JsonValueType getTypeByIndex(unsigned index) const;

	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;
	void printByKey(const MyString& searchedKey) const override;
};

