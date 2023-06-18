#pragma once
#include "../Utilities/MyString.h"
#include "JsonValue.h"

class JsonNode {
	MyString key;
	JsonValue* value; 

	void copyFrom(const JsonNode& other);
	void free();
	void moveFrom(JsonNode&& other);

public:
	JsonNode();
	JsonNode(const MyString& key,JsonValue* value);

	JsonNode(const JsonNode& other);
	JsonNode& operator=(const JsonNode& other);

	JsonNode(JsonNode&& other) noexcept;
	JsonNode& operator=(JsonNode&& other) noexcept;

	~JsonNode();

	const MyString& getKey() const;
	const JsonValue* getValue() const;
	JsonValue*& getValue();

	void setValue(JsonValue* newValue);
};