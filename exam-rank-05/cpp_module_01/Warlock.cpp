#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell*>::iterator it_begin = arr.begin();
	std::map<std::string, ASpell*>::iterator it_end = arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		it_begin++;
	}
	arr.clear();
}

const std::string& Warlock::getName() const { return name; }

const std::string& Warlock::getTitle() const { return title; }

void Warlock::setTitle(const std::string& title) { this->title = title; }

void Warlock::introduce() const { std::cout << name << ": I am " << name << ", " << title << "!" << std::endl; }

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		arr.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string spellname)
{
	std::map<std::string, ASpell*>::iterator it = arr.find(spellname);
	if (it != arr.end())
		delete it->second;
	arr.erase(spellname);
}

void Warlock::launchSpell(std::string spellname, ATarget &target)
{
	ASpell *spell = arr[spellname];
	if (spell)
		spell->launch(target);
}
