#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define N 2

int main()
{
	AAnimal *animals[N];
	int i = 0;
	for (i = 0; i < N / 2; i++)
		animals[i] = new Dog();
	for (; i < N; i++)
		animals[i] = new Cat();
	for (i = 0; i < N; i++)
		animals[i]->makeSound();
	for (i = 0; i < N; i++)
		delete animals[i];
	return 0;
}

// int main()
// {
// 	AAnimal animal;
// }
