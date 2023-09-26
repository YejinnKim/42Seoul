#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(const ASpell &obj)
{
	name = obj.name;
	effects = obj.effects;
}

ASpell& ASpell::operator=(const ASpell &obj) 
{
	name = obj.name;
	effects = obj.effects;
	return *this;
}

ASpell::~ASpell() {}

const std::string& ASpell::getName() const { return name; }

const std::string& ASpell::getEffects() const { return effects; }

void ASpell::launch(const ATarget &obj) { obj.getHitBySpell(*this); }
