#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	protected:
		Brain* brain;

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