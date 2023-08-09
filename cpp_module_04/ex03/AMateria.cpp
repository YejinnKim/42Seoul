#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &ref)
{
	type = ref.type;
}

AMateria&	AMateria::operator=(const AMateria &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

AMateria::~AMateria()
{

}

std::string	const & AMateria::getType() const
{
	return type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "* No Materia *" << std::endl;
}