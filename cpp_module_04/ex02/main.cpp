#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal animal = new Animal(); // error
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	return 0;
}