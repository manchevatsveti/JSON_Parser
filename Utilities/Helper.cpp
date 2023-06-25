#include "Helper.h"

bool Helper::isDigit(const char ch)
{
	if (ch < '0' || ch>'9') {
		return false;
	}
	return true;
}

void Helper::skipWhitespaces(std::istream& ifs)
{
	while (ifs.peek() == ' ') {
		ifs.ignore();
	}
}

void Helper::removeQuotes(MyString& str)
{
	str = str.substr(1, str.length() - 2);
}

MyString Helper::removeQuotes(const MyString& str) {
	return str.substr(1, str.length() - 2);
}

void Helper::readValue(std::stringstream& ss, MyString& str)
{
	skipWhitespaces(ss);
	char searchedKey[1024];
	ss.getline(searchedKey, 1024, '\t');
	str = std::move(searchedKey);//move op= of MyString
	removeQuotes(str);
}

void Helper::readData(std::stringstream& ss, MyString& str)
{
	skipWhitespaces(ss);
	ss.ignore();//reading '\"'
	char searchedKey[1024];
	ss.getline(searchedKey, 1024, '\"');
	str = std::move(searchedKey);//move op= of MyString
	str.substr(0, str.length() - 1);
}

size_t Helper::getFileLength(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	file.clear();
	return fileSize;
}

MyString Helper::getFileContent(std::ifstream& ifs)
{
	size_t currentPos = ifs.tellg();

	size_t size = getFileLength(ifs);
	char* temp = new char[size+1];

	for (int i=0; i < size; i++) {
		temp[i]=ifs.get();
	}
	temp[size] = '\0';

	ifs.seekg(currentPos);
	ifs.clear();

	MyString fileContent(temp);

	delete[] temp;

	return fileContent;
}

size_t Helper::getNextElementIndex(const StringView& obj)
{
	int counterObjects = 0;
	int counterArrays = 0;

	size_t size = obj.length();

	for (int i = 0; i < size; i++) {
		if (obj[i] == '{') {
			counterObjects++;
		}else if (obj[i] == '}') {
			counterObjects--;
			if (counterObjects < 0) {
				throw std::invalid_argument("Too many closing object brackets!");
			}
		}else if (obj[i] == '[') {
			counterArrays++;
		}
		else if (obj[i] == ']') {
			counterArrays--;
			if (counterArrays < 0) {
				throw std::invalid_argument("Too many closing array brackets!");
			}
		}

		if (obj[i] == ',' && counterObjects == 0 && counterArrays == 0) {
			return i;
		}
	}

	return size;
}

size_t Helper::getContainerSize(const StringView& value)
{
	int counter = 0;
	int counterObjects = 0;
	int counterArrays = 0;

	size_t size = value.length();

	for (int i = 0; i < size; i++) {
		if (value[i] == '{') {
			counterObjects++;
		}
		else if (value[i] == '}') {
			counterObjects--;
			if (counterObjects < 0) {
				throw std::invalid_argument("Too many closing object brackets!");
			}
		}
		else if (value[i] == '[') {
			counterArrays++;
		}
		else if (value[i] == ']') {
			counterArrays--;
			if (counterArrays < 0) {
				throw std::invalid_argument("Too many closing array brackets!");
			}
		}

		if (value[i] == ',' && counterObjects == 0 && counterArrays == 0) {
			counter++;
		}
	}

	return counter;
}
