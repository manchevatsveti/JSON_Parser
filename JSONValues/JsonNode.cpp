#include "JsonNode.h"

void JsonNode::copyFrom(const JsonNode& other)
{
    key = other.key;
    value = other.getValue()->clone();
}

void JsonNode::free()
{
    delete value;
    key = "";
}

void JsonNode::moveFrom(JsonNode&& other)
{
    key = other.key;
    value = other.value;
    other.value = nullptr;
}

JsonNode::JsonNode():value(nullptr){}

JsonNode::JsonNode(const MyString& key,JsonValue* value) : key(key),value(value)
{}

JsonNode::JsonNode(const JsonNode& other)
{
    copyFrom(other);
}

JsonNode& JsonNode::operator=(const JsonNode& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

JsonNode::JsonNode(JsonNode&& other) noexcept
{
    moveFrom(std::move(other));
}

JsonNode& JsonNode::operator=(JsonNode&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

JsonNode::~JsonNode()
{
    free();
}

const MyString& JsonNode::getKey() const
{
    return key;
}

const JsonValue* JsonNode::getValue() const
{
    return value;
}

JsonValue* JsonNode::getValue()
{
    return value;
}

void JsonNode::setValue(JsonValue* newValue)
{
    value = newValue;
}
