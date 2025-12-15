#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	private:
		// Private member variables here

	public:
		// Default constructor
		Brain();
		// Copy constructor
		Brain(const Brain& other);
		// Copy assignment operator
		Brain& operator=(const Brain& other);

		// Public members
		std::string ideas[100];
		
		// Destructor
		~Brain();
};

#endif