#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	type = "ice";	
}

Ice::Ice(const Ice &ref)
{
	type = ref.type;
}

Ice& Ice::operator=(const Ice &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

Ice::~Ice()
{

}

AMateria*	Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
