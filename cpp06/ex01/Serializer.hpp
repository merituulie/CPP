
#pragma once

#include "Data.hpp"

typedef unsigned long int	uintptr_t;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& rhs);

		Serializer& operator=(const Serializer& rhs);
	public:
		~Serializer(void);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
