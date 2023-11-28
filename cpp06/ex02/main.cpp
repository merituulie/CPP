
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Test : public Base {};

Base* generate(void)
{
	int random = (std::rand() % 3);
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	return new C;
}

void identify(Base* p)
{
	if (p == NULL)
	{
		std::cout << "Object can't be identified\n";
		return ;
	}
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Object is of type A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Object is of type B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Object is of type C\n";
	else
		std::cout << "Object can't be identified\n";
}

void identify(Base& p)
{
	Base object;

	try
	{
		object = dynamic_cast<A&>(p);
		std::cout << "Object is of type A\n";

		return;
	}
	catch(std::bad_cast& e)
	{
	}

	try
	{
		object = dynamic_cast<B&>(p);
		std::cout << "Object is of type B\n";

		return;
	}
	catch(std::bad_cast& e)
	{
	}

	try
	{
		object = dynamic_cast<C&>(p);
		std::cout << "Object is of type C\n";

		return;
	}
	catch(std::bad_cast& e)
	{
	}

	std::cout << "Object can't be identified\n";
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int object_count = 10;
	Base *objects[object_count];

	std::cout << "Creating " << object_count << " objects...\n";
	for (int i = 0; i < object_count - 2; i++)
		objects[i] = generate();
	objects[object_count - 2] = new Test;
	objects[object_count - 1] = NULL;
	std::cout << std::endl;

	std::cout << "Identifying " << object_count << " objects by pointers...\n";
	for (int i = 0; i < object_count; i++)
		identify(objects[i]);
	std::cout << std::endl;

	std::cout << "Identifying " << object_count << " objects by references...\n";
	for (int i = 0; i < object_count; i++)
		identify(*objects[i]);
	std::cout << std::endl;

	std::cout << "Clearing " << object_count << " objects...\n";
	for (int i = 0; i < object_count; i++)
		delete objects[i];
	return 0;
}
