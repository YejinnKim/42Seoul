#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	vector;
		std::deque<int>		deque;
		clock_t	startTime;
		double	vectorTime;
		double	dequeTime;

		PmergeMe();
		// vector
		void	mergeSort(std::vector< std::pair<int, int> > &arr, size_t start, size_t end);
		void	insertSort(std::vector<int> &main, std::vector<int> &pending, int last);
		size_t	binarySearch(std::vector<int> &arr, size_t start, size_t end, int target);
		// deque
		void	mergeSort(std::deque< std::pair<int, int> > &arr, size_t start, size_t end);
		void	insertSort(std::deque<int> &main, std::deque<int> &pending, int last);
		size_t	binarySearch(std::deque<int> &arr, size_t start, size_t end, int target);
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		void	printVector() const;
		void	printTime() const;

		void	sortVector();
		void	sortDeque();
};

void	printError();

#endif
