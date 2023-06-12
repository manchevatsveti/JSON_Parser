#include "JsonNode.h"

JsonNode::JsonNode(const MyString& key,JsonValue* value) : key(key),value(value)
{}

const MyString& JsonNode::getKey() const
{
    return key;
}

const JsonValue* JsonNode::getValue() const
{
    return value;
}
