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
		std::vector< std::pair<int, int> >	vtmp;
		std::deque< std::pair<int, int> >	dtmp;
		double	vectorTime;
		double	dequeTime;

		PmergeMe();
		void	nextJacob(size_t &jacob1, size_t &jacob2);
		// vector
		size_t	binarySearchVector(size_t start, size_t end, int target);
		void	insertSortVector(int last);
		void	mergeSortVector(size_t start, size_t end);
		void	createPairVector(size_t len);
		// deque
		size_t	binarySearchDeque(size_t start, size_t end, int target);
		void	insertSortDeque(int last);
		void	mergeSortDeque(size_t start, size_t end);
		void	createPairDeque(size_t len);
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
