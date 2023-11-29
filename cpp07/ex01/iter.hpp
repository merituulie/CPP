
#pragma once

#include <iostream>

template<typename T, typename F>
void iter(T *array, size_t size, F func)
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template<typename T>
void printNode(const T& node)
{
	std::cout << node << std::endl;
}
