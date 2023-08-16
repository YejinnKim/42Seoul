#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "-----Upcasting Test-----" << std::endl;
	const Animal *animal[4];

	for (int i=0; i < 4; i++)
	{
		if (i < 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i=0; i < 4; i++)
	{
		delete animal[i];
		std::cout << std::endl;
	}

	std::cout << "-----DeepCopy Test-----" << std::endl;
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();
	std::cout << std::endl;

	std::cout << cat1->getBrain().getIdea(0) << std::endl;
	std::cout << cat2->getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;

	*cat1 = *cat2;
	cat1->getBrain().setIdea(0, "new idea!");
	std::cout << std::endl;

	std::cout << cat1->getBrain().getIdea(0) << std::endl;
	std::cout << cat2->getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;

	delete cat1;
	delete cat2;
	return 0;
}