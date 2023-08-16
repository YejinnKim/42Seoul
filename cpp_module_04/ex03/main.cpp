#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

// int main()
// {
// 	IMateriaSource *src = new MateriaSource();
// 	ICharacter *me = new Character("me");
// 	ICharacter *bob = new Character("bob");

// 	src->createMateria("ice"); // empty slot
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice()); // full slot

// 	me->equip(src->createMateria("test")); // invalid materia
// 	me->equip(src->createMateria("ice"));
// 	me->equip(src->createMateria("cure"));
// 	me->equip(src->createMateria("ice"));
// 	me->equip(src->createMateria("cure"));
// 	me->equip(src->createMateria("ice")); // full slot

// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->use(2, *bob);
// 	me->use(3, *bob);
// 	me->use(4, *bob); // invalid index

// 	Character *tmp = (Character *)me;
// 	AMateria *floor = tmp->getMateria(0);
// 	delete floor;

// 	me->unequip(0);
// 	me->use(0, *bob);
// 	me->unequip(3); // invalid index
	
// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }
