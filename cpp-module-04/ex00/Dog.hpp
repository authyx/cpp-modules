#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		// Default constructor
		Dog();
		
		// Copy constructor
		Dog(const Dog& other);
		
		// Copy assignment operator
		Dog& operator=(const Dog& other);

		void makeSound() const;
		
		// Destructor
		~Dog();
};

#endif