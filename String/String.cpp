#include "String.h"
#pragma warning (disable : 4996)

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

static unsigned capacityToAllocate(unsigned stringLength)
{
	return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

void String::free()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

void String::copyFrom(const String& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new char[capacity];
	strcpy(data, other.data);
}

void String::moveFrom(String&& other) noexcept
{
	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity = 0;

	data = other.data;
	other.data = nullptr;
}

void String::resize(unsigned newCapacity)
{
	capacity = newCapacity;

	char* newData = new char[capacity + 1];
	strcpy(newData, data);

	delete[] data;
	data = newData;
}

String::String(unsigned stringLength)
{
	capacity = capacityToAllocate(stringLength);
	data = new char[capacity];
	size = 0;
	data[0] = '\0';
}

String::String() : String("") {};

String::String(const char* data)
{
	size = strlen(data);
	capacity = capacityToAllocate(size);
	this->data = new char[capacity];
	strcpy(this->data, data);
}

String::String(const String& other)
{
	copyFrom(other);
}

String::String(String&& other) noexcept
{
	moveFrom(std::move(other));
}

String& String::operator=(const String& other)
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other) 
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

String::~String()
{
	free();
}

unsigned String::getCapacity() const
{
	return capacity;
}

unsigned String::getSize() const
{
	return size;
}

const char* String::c_str() const
{
	return data;
}

String& String::operator+=(const String& other)
{
	if (size + other.size + 1> capacity)
		resize(capacityToAllocate(size + other.size));

	strncat(data, other.data, other.size);
	return *this;
}

char& String::operator[](unsigned index)
{
	return data[index];
}

const char& String::operator[](unsigned index) const
{
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.data;
}

std::istream& operator>>(std::istream& is, String& obj)
{
	char buff[1024];
	is >> buff;

	size_t buffStringSize = strlen(buff);

	if (buffStringSize > obj.capacity)
		obj.resize(buffStringSize);

	strcpy(obj.data, buff);
	obj.size = buffStringSize;
	return is;
}

String operator+(const String& lhs, const String& rhs)
{
	String result(lhs.size + rhs.size);
	result += lhs;
	result += rhs;
	return result;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}


bool operator>=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
