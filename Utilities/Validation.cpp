#include "Validation.h"
#include "MyString.h"
#include "Helper.h"

bool Validation::isNumber(std::istream& ifs)
{
	return true;
}

bool Validation::isValidValue(const StringView& value)
{
	return (isValidArray(value)||isValidBool(value)||isValidString(value)||isValidNode(value)||isValidNull(value)||
			isValidNumber(value)||isValidObject(value));
}

bool Validation::isValidObject(const StringView& value)
{
	if (value[0] != '{' || value[value.length()-1] != '}') {
		return false;
	}

	StringView obj(value.substr(1, value.length() - 2));

	size_t size = Helper::getContainerSize(obj);

	for (int i = 0; i < size; i++) {
		size_t currentEnd = Helper::getNextElementIndex(obj);

		if (isValidNode(obj.substr(0, currentEnd)) == false) {
			return false;
		}

		obj = obj.substr(currentEnd + 1, obj.length() - currentEnd - 1);
	}
	return true;

}

bool Validation::isValidNode(const StringView& nodeContent)
{
	size_t size = nodeContent.length();
	size_t columnIndex = 0;

	for (int i = 0; i < size; i++) {
		if (nodeContent[i] == ':') {
			columnIndex = i;
			break;
		}
	}

	if (columnIndex == 0) {
		return false;
	}

	StringView key(nodeContent.substr(0, columnIndex));
	StringView value(nodeContent.substr(columnIndex+1, size- columnIndex-1));

}

bool Validation::isValidString(const StringView& str)
{
	if (str[0] != '"' || str[str.length() - 1] != '"') {
		return false;
	}
	return true;
}

bool Validation::isValidArray(const StringView& value)
{
	if (value[0] != '[' || value[value.length() - 1] != ']') {
		return false;
	}

	StringView arr(value.substr(1, value.length() - 2));

	size_t size = Helper::getContainerSize(arr);

	size_t currentBeg = 0;

	for (int i = 0; i < size; i++) {
		size_t currentEnd = Helper::getNextElementIndex(arr);

		if (isValidValue(arr.substr(currentBeg, currentEnd)) == false) {
			return false;
		}
		
		currentBeg = currentEnd;
		arr = arr.substr(currentBeg + 1, arr.length() - currentBeg - 1);
	}
	return true;
}

bool Validation::isValidBool(const StringView& value)
{
	if (value[0] != 't' && value[0] != 'f') {
		return false;
	}

	if (value == "true" || value == "false") {
		return true;
	}

	return false;
}

bool Validation::isValidNull(const StringView& value)
{
	if (value[0] != 'n') {
		return false;
	}

	if (value == "null") {
		return true;
	}

	return false;
}

bool Validation::isValidNumber(const StringView& value)
{
	size_t beg = 0;
	if (value[0] == '-') {
		beg++;
	}

	size_t size = value.length();

	for (int i = beg; i<size; i++) {
		if (!Helper::isDigit(value[i])) {
			return false;
		}
	}
	return true;
}
