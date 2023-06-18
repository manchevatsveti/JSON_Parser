#pragma once
#include "JSONValues/JsonObject.h"
#include "Utilities/MyString.h"

class JsonFileHandler
{
	MyString _filename;
	JsonObject* obj;

	bool isValidFile(const MyString& fileContent) const;

public:
	JsonFileHandler();

	JsonObject* readJsonFile(const MyString& filename);

	void open(const MyString& filename);
	void close();

	void print(std::ostream& ofs) const;
	void printByKey(const MyString& searchedKey) const;
	void setByKey(const MyString& filepath, const MyString& newValue);
	void createByKey(const MyString& filepath, const MyString& newValue);
	void deleteBypath(const MyString& filepath);
	void moveFromTo(const MyString& filePathFrom, const MyString& filePathTo);
	void saveAs(const MyString& filepath, const MyString& filename);
	void save(const MyString& filepath);

	~JsonFileHandler();
};

