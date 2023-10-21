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
		size_t	binarySearch(std::vector<int> &arr, size_t start, size_t end, int target);
		void	insertSort(std::vector<int> &main, std::vector<int> &pending, int last);
		void	mergeSort(std::vector< std::pair<int, int> > &tmp, size_t start, size_t end);
		void	createPair(std::vector< std::pair<int, int> > &tmp, size_t len);
		// deque
		size_t	binarySearch(std::deque<int> &arr, size_t start, size_t end, int target);
		void	insertSort(std::deque<int> &main, std::deque<int> &pending, int last);
		void	mergeSort(std::deque< std::pair<int, int> > &arr, size_t start, size_t end);
		void	createPair(std::deque< std::pair<int, int> > &tmp, size_t len);
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		void	printVector() const;
		void	printTime() const;
		void	checkSort() const;

		void	sortVector();
		void	sortDeque();
};

void	printError();

#endif
