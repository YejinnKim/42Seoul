#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // ?

void	print_error(std::string str)
{
	std::cout << str << std::endl;
	exit(0);
}

void	replace_line(std::string s1, std::string s2, std::ifstream &ifs, std::ofstream &ofs)
{
	std::string	line;
	bool		flag = true;
	size_t		pos;

	if (!s1.length())
		print_error("s1 is empty.");
	while (1)
	{
		if (flag)
			std::getline(ifs, line);
		pos = line.find(s1);
		if (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
		}
		if (line.find(s1) != std::string::npos)
			flag = false;
		else
		{
			flag = true;
			ofs << line;
		}
		if (ifs.eof())
			break;
	}
}

int main(int argc, char **argv)
{
	std::string		filename;
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (argc != 4)
		print_error("There're not 3 arguments.");

	filename = argv[1];
	ifs.open(filename.c_str()); // c_str()
	if (ifs.fail())
		print_error("Can't open file.");
	filename.append(".replace");
	ofs.open(filename.c_str()); // c_str()
	if (ofs.fail())
		print_error("Can't open file.");

	replace_line(argv[2], argv[3], ifs, ofs);

	ifs.close();
	ofs.close();
	return (0);
}
