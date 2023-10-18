#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	vector;
		std::list<int>		list;
		clock_t	startTime;
		double	vectorTime;
		double	listTime;
		
		PmergeMe();
		void	mergeSort(std::vector< std::pair<int, int> > &arr, size_t start, size_t end);
		size_t	binarySearch(std::vector<int> result, size_t start, size_t end, int target);

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		void	printVector() const;
		void	printTime() const;

		void	sortVector();
		void	sortList();
};

void	printError();

#endif
