#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	name = "Fwoosh";
	effects = "fwooshed";
}

Fwoosh::~Fwoosh() {}

ASpell* Fwoosh::clone() const { return new Fwoosh(); }
