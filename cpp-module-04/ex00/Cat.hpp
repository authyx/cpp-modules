#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		// Default constructor
		Cat();
		
		// Copy constructor
		Cat(const Cat& other);
		
		// Copy assignment operator
		Cat& operator=(const Cat& other);

		void makeSound() const;
		
		// Destructor
		~Cat();
};

#endif