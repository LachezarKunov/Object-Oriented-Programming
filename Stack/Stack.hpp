#include <iostream>

template<class T>
class Stack 
{
private:
	size_t size = 0;
	size_t capacity = 8;
	T* data = new T[capacity];

	void free();
	void copyFrom(const Stack& other);
	void moveFrom(Stack&& other);
	void resize(size_t newCap);

public:
	Stack() = default;
	Stack(const Stack& other);
	Stack(Stack&& other);
	Stack& operator=(const Stack& other);
	Stack& operator=(Stack&& other);
	~Stack();

	void push(const T& obj);
	void push(T&& obj);

	const T& peek() const;
	void pop();

	bool isEmpty() const;
};

template<class T>
void Stack<T>::free()
{
	delete[] data;
	data = nullptr;
}

template<class T>
void Stack<T>::copyFrom(const Stack& other)
{
	size = other.size;
	capacity = other.capacity;
	
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<class T>
void Stack<T>::moveFrom(Stack&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<class T>
void Stack<T>::resize(size_t newCap)
{
	T* newData = new T[newCap];

	for (size_t i = 0; i < newCap; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;

	capacity = newCap;
}

template<class T>
Stack<T>::Stack(const Stack& other)
{
	copyFrom(other);
}

template<class T>
Stack<T>::Stack(Stack&& other)
{
	moveFrom(std::move(other));
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
Stack<T>& Stack<T>::operator=(Stack&& other)
{
	if (this != &other) 
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
Stack<T>::~Stack()
{
	free();
}

template<class T>
void Stack<T>::push(const T& obj)
{
	if (size == capacity)
		resize(capacity * 2);
	
	data[size++] = obj;
}

template<class T>
void Stack<T>::push(T&& obj)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = std::move(obj);
}

template<class T>
const T& Stack<T>::peek() const
{
	if (isEmpty())
		throw std::out_of_range("Error!");

	return data[size - 1];
}

template<class T>
void Stack<T>::pop()
{
	if (isEmpty())
		throw std::out_of_range("Error!");
	
	size--;
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return size == 0;
}
