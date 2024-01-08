
#pragma once

#include <stdexcept>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		~Array(void);
		Array(void);
		Array(unsigned int n);
		Array(const Array& rhs);

		Array& operator=(const Array& rhs);
		T& operator[](unsigned int index);

		unsigned int size() const;
};

template<typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template<typename T>
Array<T>::Array(const Array& rhs) : _array(new T[rhs._size]), _size(rhs._size)
{
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = rhs._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		if (rhs._size != this->_size)
		{
			delete [] _array;
			_array = new T[rhs._size];
			_size = rhs._size;
		}

		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}

	return *this;
}

template<typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size || index < 0)
		throw OutOfBoundsException();
	else
		return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what(void) const throw()
{
	return "Index out of bounds";
}
