#pragma once
#include "JsonValue.h"
#include "../Utilities/Vector.hpp"
#include "../Utilities/SharedPtr.hpp"

class JsonArray : public JsonValue
{
	Vector<SharedPtr<JsonValue>> values;

public:
	JsonArray();

	void addValue(JsonValueType valuesType);
	void addValue(SharedPtr<JsonValue> value);
	void removeValue(size_t index);

	const JsonValueType& getTypeByIndex(unsigned index) const;

	JsonValue* clone() const override;

	void print(std::ostream& ofs) const override;
	void writeToFile(std::ostream& ofs) const override;

	size_t getSize() const;
	const JsonValue* getElement(size_t index) const;
};

