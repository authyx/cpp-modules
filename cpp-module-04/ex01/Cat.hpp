#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* brain;

	protected:
		std::string sound;

	public:
		// Default constructor
		Cat();
		
		// Copy constructor
		Cat(const Cat& other);
		
		// Copy assignment operator
		Cat& operator=(const Cat& other);

		void makeSound() const;

		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
		
		// Destructor
		~Cat();
};

#endif