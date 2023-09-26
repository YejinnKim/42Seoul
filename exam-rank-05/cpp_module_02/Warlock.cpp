#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << name << ": My job here is done!" << std::endl; }

const std::string& Warlock::getName() const { return name; }

const std::string& Warlock::getTitle() const { return title; }

void Warlock::setTitle(const std::string& title) { this->title = title; }

void Warlock::introduce() const { std::cout << name << ": I am " << name << ", " << title << "!" << std::endl; }

void Warlock::learnSpell(ASpell* spell) { book.learnSpell(spell); }

void Warlock::forgetSpell(std::string name) { book.forgetSpell(name); }

void Warlock::launchSpell(std::string name, ATarget &target)
{
	// ***확인***
	ATarget const *test = 0;
	if (test == &target)
		return ;
	// ***중요***
	ASpell *tmp = book.createSpell(name);
	if (tmp)
		tmp->launch(target);
}
