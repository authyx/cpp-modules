#ifndef ANIMAL_CPP
#define ANIMAL_CPP

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
	
	virtual void makeSound() const;
	virtual ~Animal();
};

#endif