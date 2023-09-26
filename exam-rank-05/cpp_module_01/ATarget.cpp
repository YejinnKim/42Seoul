#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) { this->type = type; }

ATarget::ATarget(const ATarget &obj) { *this = obj; }

ATarget& ATarget::operator=(const ATarget &obj)
{
	type = obj.type;
	return *this;
}

ATarget::~ATarget() {}

const std::string& ATarget::getType() const { return type; }

void ATarget::getHitBySpell(const ASpell &spell) const { std::cout << type << " has beeb " << spell.getEffects() << "!" << std::endl; }
