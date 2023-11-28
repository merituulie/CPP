
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	{
		std::cout << "------------TEST 1------------" << std::endl;
		int value = 100;
		Data data;
		data.value = value;

		std::cout << "SERIALIZING....." << std::endl;
		uintptr_t serialized = Serializer::serialize(&data);
		std::cout << "DE-SERIALIZING....." << std::endl;
		Data *deserialized = Serializer::deserialize(serialized);

		if (deserialized->value != 100)
		{
			std::cerr << "\033[33mFAIL:\nDE-SERIALIZED DATA SHOULD BE " << value << "\nBUT WAS" << deserialized->value << " \033[0m" << std::endl;
			std::cout << "------------------------------" << std::endl;
		}
		else
			std::cout << "\033[32mOKAY\033[0m" << std::endl;
	}

	{
		std::cout << "------------TEST 2------------" << std::endl;
		int value = -100;
		Data data;
		data.value = value;

		std::cout << "SERIALIZING....." << std::endl;
		uintptr_t serialized = Serializer::serialize(&data);
		std::cout << "DE-SERIALIZING....." << std::endl;
		Data *deserialized = Serializer::deserialize(serialized);

		if (deserialized->value != -100)
		{
			std::cerr << "\033[33mFAIL:\nDE-SERIALIZED DATA SHOULD BE " << value << "\nBUT WAS" << deserialized->value << " \033[0m" << std::endl;
			std::cout << "------------------------------" << std::endl;
		}
		else
			std::cout << "\033[32mOKAY\033[0m" << std::endl;
	}
}
