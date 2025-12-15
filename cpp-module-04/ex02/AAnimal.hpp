#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string type;
	std::string sound;

public:
	
	AAnimal();
	AAnimal(const AAnimal& A);

	std::string getType() const;

	AAnimal& operator = (const AAnimal& org);

	virtual void makeSound() const = 0;
	virtual ~AAnimal();
};

#endif