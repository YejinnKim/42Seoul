#pragma once

#include <iostream>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(const Warlock &obj);
		Warlock& operator=(const Warlock &obj);

		std::map<std::string, ASpell*> arr;
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& title);

		void introduce() const;

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellname);
		void launchSpell(std::string spellname, ATarget &target);
};
