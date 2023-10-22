#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	vectorTime = 0;
	dequeTime = 0;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			if (!isdigit(argv[i][j]))
				printError();
		int value = atoi(argv[i]);
		if (value <= 0)
			printError();
		vector.push_back(value);
		deque.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		vector = obj.vector;
		deque = obj.deque;
		vtmp = obj.vtmp;
		dtmp = obj.dtmp;
		vectorTime = obj.vectorTime;
		dequeTime = obj.dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::printVector() const
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printTime() const
{
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

void	PmergeMe::checkSort() const
{
	for (size_t i = 0; i < vector.size() - 1; i++)
	{
		if (vector[i] > vector[i + 1] || deque[i] > deque[i + 1])
		{
			std::cout << "Sort failed!!!" << std::endl;
			exit(1);
		}
	}
}

void	PmergeMe::nextJacob(size_t &jacob1, size_t &jacob2)
{
	size_t tmp = jacob2;
	jacob2 = jacob2 + (jacob1 * 2);
	jacob1 = tmp;
}

size_t	PmergeMe::binarySearchVector(size_t start, size_t end, int target)
{
	if (end <= start)
		return end;
	size_t mid = start + (end - start) / 2;
	if (vector[mid] == target)
		return mid;
	else if (vector[mid] < target)
		return binarySearchVector(mid + 1, end, target);
	else
		return binarySearchVector(start, mid, target);
}

void	PmergeMe::insertSortVector(int last)
{
	size_t jacob1 = 1, jacob2 = 1;
	size_t i = 0, index, size = vtmp.size();

	vector.clear();
	for (size_t j=0; j < size; j++)
		vector.push_back(vtmp[j].first);
	vector.insert(vector.begin(), vtmp[0].second);
	while (i < size)
	{
		if (i == jacob1 - 1)
		{
			if (jacob2 >= size)
				break;
			nextJacob(jacob1, jacob2);
			if (jacob2 > size)
				i = size - 1;
			else
				i = jacob2 - 1;
		}
		index = binarySearchVector(0, vector.size(), vtmp[i].second);
		vector.insert(vector.begin() + index, vtmp[i].second);
		i--;
	}
	if (last)
	{
		index = binarySearchVector(0, vector.size(), last);
		vector.insert(vector.begin() + index, last);
	}
}

void	PmergeMe::mergeSortVector(size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t mid = start + (end - start) / 2;

		mergeSortVector(start, mid);
		mergeSortVector(mid, end);

		std::vector< std::pair<int, int> > sorted(end - start);
		size_t i = start, j = mid, k = 0;
		while (i < mid && j < end)
		{
			if (vtmp[i].first < vtmp[j].first)
				sorted[k++] = vtmp[i++];
			else
				sorted[k++] = vtmp[j++];
		}
		while (i < mid) sorted[k++] = vtmp[i++];
		while (j < end) sorted[k++] = vtmp[j++];

		for (k = 0, i = start; i < end; i++, k++)
			vtmp[i] = sorted[k];
	}
}

void	PmergeMe::createPairVector(size_t len)
{
	for (size_t i = 0; i + 1 < len; i += 2)
	{
		if (vector[i] > vector[i + 1])
			vtmp.push_back(std::pair<int, int>(vector[i], vector[i + 1]));
		else
			vtmp.push_back(std::pair<int, int>(vector[i + 1], vector[i]));
	}
	mergeSortVector(0, len / 2);
}

void	PmergeMe::sortVector()
{
	clock_t startTime = clock();

	size_t len = vector.size();
	if (len < 2)
		return ;

	int last = 0;
	if (len % 2 != 0)
		last = vector[len - 1];

	createPairVector(len);
	insertSortVector(last);

	vectorTime = (double)(clock() - startTime);
}

size_t	PmergeMe::binarySearchDeque(size_t start, size_t end, int target)
{
	if (end <= start)
		return end;
	size_t mid = start + (end - start) / 2;
	if (deque[mid] == target)
		return mid;
	else if (deque[mid] < target)
		return binarySearchDeque(mid + 1, end, target);
	else
		return binarySearchDeque(start, mid, target);
}

void	PmergeMe::insertSortDeque(int last)
{
	size_t jacob1 = 1, jacob2 = 1;
	size_t i = 0, index, size = dtmp.size();

	deque.clear();
	for (size_t j=0; j < size; j++)
		deque.push_back(dtmp[j].first);
	deque.insert(deque.begin(), dtmp[0].second);
	while (i < size)
	{
		if (i == jacob1 - 1)
		{
			if (jacob2 >= size)
				break;
			nextJacob(jacob1, jacob2);
			if (jacob2 > size)
				i = size - 1;
			else
				i = jacob2 - 1;
		}
		index = binarySearchDeque(0, deque.size(), dtmp[i].second);
		deque.insert(deque.begin() + index, dtmp[i].second);
		i--;
	}
	if (last)
	{
		index = binarySearchDeque(0, deque.size(), last);
		deque.insert(deque.begin() + index, last);
	}
}

void	PmergeMe::mergeSortDeque(size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t mid = start + (end - start) / 2;

		mergeSortDeque(start, mid);
		mergeSortDeque(mid, end);

		std::deque< std::pair<int, int> > sorted(end - start);
		size_t i = start, j = mid, k = 0;
		while (i < mid && j < end)
		{
			if (dtmp[i].first < dtmp[j].first)
				sorted[k++] = dtmp[i++];
			else
				sorted[k++] = dtmp[j++];
		}
		while (i < mid) sorted[k++] = dtmp[i++];
		while (j < end) sorted[k++] = dtmp[j++];

		for (k = 0, i = start; i < end; i++, k++)
			dtmp[i] = sorted[k];
	}
}

void	PmergeMe::createPairDeque(size_t len)
{
	for (size_t i = 0; i + 1 < len; i += 2)
	{
		if (deque[i] > deque[i + 1])
			dtmp.push_back(std::pair<int, int>(deque[i], deque[i + 1]));
		else
			dtmp.push_back(std::pair<int, int>(deque[i + 1], deque[i]));
	}
	mergeSortDeque(0, len / 2);
}

void	PmergeMe::sortDeque()
{
	clock_t startTime = clock();

	size_t len = deque.size();
	if (len < 2)
		return ;

	int last = 0;
	if (len % 2 != 0)
		last = deque[len - 1];

	createPairDeque(len);	
	insertSortDeque(last);

	dequeTime = (double)(clock() - startTime);
}

void	printError()
{
	std::cout << "Error" << std::endl;
	exit(1);
}
