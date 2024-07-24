#pragma once
#include <iostream>
#include <fstream>
#include "String.h"

class StringView 
{
private:
	const char* begin;
	const char* end;

public:
	StringView(const char* str);
	StringView(const char* begin, const char* end);
	StringView(const String& string);

	size_t length() const;
	char operator[](size_t index) const;

	StringView substr(size_t from, size_t length) const;
	friend std::ostream& operator<<(std::ostream& os, const StringView& obj);
};

bool operator==(const StringView& lhs, const StringView& rhs);
bool operator!=(const StringView& lhs, const StringView& rhs);
