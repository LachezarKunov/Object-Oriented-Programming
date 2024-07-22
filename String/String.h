#pragma once
#include <fstream>

class String
{
private:
	char* data;
	unsigned size;
	unsigned capacity;

	void free();
	void copyFrom(const String& other);
	void moveFrom(String&& other) noexcept;

	void resize(unsigned newCapacity);

	explicit String(unsigned stringLength);

public:
	String();
	String(const char* data);

	String(const String& other);
	String(String&& other) noexcept;

	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;

	~String();

	unsigned getCapacity() const;
	unsigned getSize() const;

	const char* c_str() const;

	String& operator+=(const String& other);

	char& operator[](unsigned index);
	const char& operator[](unsigned index) const;

	friend std::ostream& operator<<(std::ostream& os, const String& obj);
	friend std::istream& operator>>(std::istream& is, String& obj);
	friend String operator+(const String& lhs, const String& rhs);
};

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);