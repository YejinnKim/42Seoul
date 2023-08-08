#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "-----Wrong Test-----" << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << std::endl;

	std::cout << wrong->getType() << std::endl;
	wrong->makeSound();
	std::cout << std::endl;

	delete wrong;
	return 0;
}