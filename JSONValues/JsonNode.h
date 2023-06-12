#pragma once
#include "../Utilities/MyString.h"
#include "JsonValue.h"

class JsonNode {
	MyString key;
	JsonValue* value; 

public:
	//BIG 6??
	JsonNode() = default;
	JsonNode(const MyString& key,JsonValue* value);

	const MyString& getKey() const;
	const JsonValue* getValue() const;
};