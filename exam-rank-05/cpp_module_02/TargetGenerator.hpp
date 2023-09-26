#pragma once

#include <iostream>
#include <map>

class ATarget;

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> arr;

		TargetGenerator(const TargetGenerator &obj);
		TargetGenerator& operator=(const TargetGenerator &obj);
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &name);
		ATarget *createTarget(std::string const &name);
};
