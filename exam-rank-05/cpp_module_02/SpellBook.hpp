#pragma once

#include <iostream>
#include <map>

class ASpell;

class SpellBook
{
	private:
		std::map<std::string, ASpell*> arr;

		SpellBook(const SpellBook &obj);
		SpellBook& operator=(const SpellBook &obj);
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &name);
		ASpell* createSpell(std::string const &name);
};
