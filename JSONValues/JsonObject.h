#pragma once
#include "JsonValue.h"
#include "../Utilities/Vector.hpp"
#include "JsonNode.h"
#include <fstream>

class JsonObject : public JsonValue
{
	Vector<JsonNode> elements;

	void printArrayByKey(const JsonValue* value, const MyString& searchedKey) const;
	const JsonValueType& getTypeByIndex(size_t index) const;

public:
	JsonObject();
	JsonValue* clone() const override;

	void addElement(const MyString& key,JsonValue* value);
	void removeElement(size_t index);

	void print(std::ostream& ofs) const override;

	size_t getNodesCount() const;
	
	void printByKey(const MyString& searchedKey) const;

	const JsonValue* getElement(int index) const;
	size_t getIndexByKey(const MyString& key) const;

	void setByKey(const MyString& filepath, const MyString& newValue);
	void createByKey(const MyString& filepath, const MyString& newValue);
	void deleteBypath(const MyString& filepath);

	JsonNode& operator[](size_t index);
	const JsonNode& operator[](size_t index) const;
};

