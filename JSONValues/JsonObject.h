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

	void setValueFromPath(const MyString& filepath, JsonValue* newValue);
	const JsonValue* getValueFromPath(const MyString& filepath);

	//JsonObject* getObjByPath(const MyString& filepath, int indexSlashSymbol);

	const void openFileForWriting(const MyString& filename) const;
public:
	JsonObject();
	JsonValue* clone() const override;

	void addElement(const MyString& key,JsonValue* value);
	void removeElement(size_t index);

	const JsonValue* getElement(int index) const;
	int getIndexByKey(const MyString& key) const;
	
	void print(std::ostream& ofs) const override;
	void writeToFile(std::ostream& ofs) const override;
	void printByKey(const MyString& searchedKey) const;
	void setByKey(const MyString& filepath, const MyString& newValue);
	void createByKey(const MyString& filepath, const MyString& newValue);
	void deleteBypath(const MyString& filepath);
	void moveFromTo(const MyString& filePathFrom, const MyString& filePathTo);
	void saveAs(const MyString& filepath, const MyString& filename);

	JsonNode& operator[](size_t index);
	const JsonNode& operator[](size_t index) const;
};

