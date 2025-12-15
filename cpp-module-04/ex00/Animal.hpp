#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;
	std::string sound;
public:
	
	Animal();
	Animal(const Animal& A);

	std::string getType() const;

	Animal& operator = (const Animal& org);
	virtual ~Animal();
	
	virtual void makeSound() const;

};

#endif