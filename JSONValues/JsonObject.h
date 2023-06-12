#pragma once
#include "JsonValue.h"
#include "../Utilities/Vector.hpp"
#include "JsonNode.h"
#include <fstream>

class JsonObject : public JsonValue
{
	Vector<JsonNode> elements;

public:
	JsonObject();
	JsonValue* clone() const override;

	void addElement(const MyString& key,JsonValue* value);

	void print(std::ostream& ofs) const override;

	size_t getNodesCount() const;
	
	void printByKey(const MyString& searchedKey) const override;
	const JsonValue* getElement(int index) const;
};

