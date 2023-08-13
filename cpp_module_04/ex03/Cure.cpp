#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	type = "cure";	
}

Cure::Cure(const Cure &ref)
{
	type = ref.type;
}

Cure& Cure::operator=(const Cure &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

Cure::~Cure()
{

}

AMateria*	Cure::clone() const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
