#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"


class Dog: public Animal
{
	private:
		Brain* brain;

	protected:
		std::string sound;

	public:
		// Default constructor
		Dog();
		
		// Copy constructor
		Dog(const Dog& other);
		
		// Copy assignment operator
		Dog& operator=(const Dog& other);

		void makeSound() const;

		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
		
		// Destructor
		~Dog();
};

#endif