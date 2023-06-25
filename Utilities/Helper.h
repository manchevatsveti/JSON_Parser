#pragma once
#include <fstream>
#include "MyString.h"
#include "StringView.h"
#include <sstream>

class Helper
{
public:
	static bool isDigit(const char ch);
	static void skipWhitespaces(std::istream& ifs);

	static void removeQuotes(MyString& str);
	static MyString removeQuotes(const MyString& str);
	static void readValue(std::stringstream& ss, MyString& str);
	static  void readData(std::stringstream& ss, MyString& str);

	static size_t getFileLength(std::ifstream& ifs);//github.com/Angeld55
	static MyString getFileContent(std::ifstream& ifs);

	static size_t getNextElementIndex(const StringView& obj);
	static size_t getContainerSize(const StringView& value);
};

