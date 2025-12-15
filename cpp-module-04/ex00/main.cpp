#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


int main()
{
	{
		Animal* meta = new Animal();
		Animal* cat = new Cat();
		Animal* dog = new Dog();
		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		meta->makeSound();
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		delete meta;
		delete cat;
		delete dog;
	}
	std::cout << "---------------------" << std::endl;
	{
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* wrongcat = new WrongCat();
		std::cout << wrongcat->getType() << " " << std::endl;
		wrongcat->makeSound();
		meta->makeSound();
		delete meta;
		delete wrongcat;
	}
}
