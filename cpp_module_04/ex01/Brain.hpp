#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &ref);
		Brain& operator=(const Brain &ref);
		~Brain();

		std::string getIdea(int i);
		void		setIdea(int i, std::string idea);
};

#endif
