#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define N 100

int main()
{
	std::cout << "=== Polymorphic Animals ===" << std::endl;
	{
		Animal *animals[N];
		int i = 0;
		for (i = 0; i < N / 2; i++)
			animals[i] = new Dog();
		for (; i < N; i++)
			animals[i] = new Cat();
		for (i = 0; i < N; i++)
			animals[i]->makeSound();
		for (i = 0; i < N; i++)
			delete animals[i];
	}
	return 0;
}