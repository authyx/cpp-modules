#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	// Create Data object
	Data *original = new Data();
	original->name = "Test";
	original->value = 42;

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Original data: " << original->name << ", " << original->value << std::endl;

	// Serialize
	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized: " << raw << std::endl;

	// Deserialize
	Data *restored = Serializer::deserialize(raw);
	std::cout << "Restored pointer: " << restored << std::endl;
	std::cout << "Restored data: " << restored->name << ", " << restored->value << std::endl;

	if (original == restored)
		std::cout << "✓ Pointers are equal!" << std::endl;
	else
		std::cout << "✗ Pointers are different!" << std::endl;

	delete original;
	return 0;
}