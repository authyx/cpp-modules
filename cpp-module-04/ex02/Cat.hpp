#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	protected:
		Brain* brain;

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