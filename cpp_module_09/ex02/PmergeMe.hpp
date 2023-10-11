#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	vector;
		std::list<int>		list;
		clock_t	vectorTime;
		clock_t	listTime;
		int	k;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		void	init(int argc, char **argv);
		void	sort();

		void	vectorSort();
		void	vectorMergeInsertionSort(int left, int right);
		void	vectorInsertionSort(int left, int right);
		void	vectorMerge(int left, int mid, int right);

		// void	listSort();
		// void	listMergeInsertionSort();
		// void	listInsertionSort();
		// void	listMerge();
};

void	printError();

#endif
