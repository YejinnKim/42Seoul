#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			if (!isdigit(argv[i][j]))
				printError();
		int value = atoi(argv[i]);
		if (value < 0)
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
		startTime = obj.startTime;
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

void	PmergeMe::sortVector()
{
	startTime = clock();

	size_t len = vector.size();
	if (len < 2)
		return ;
	
	int last = 0;
	if (len % 2 != 0)
		last = vector[len - 1];

	std::vector< std::pair<int, int> > tmp;
	for (size_t i = 0; i + 1 < len; i += 2)
	{
		std::pair<int, int> pair;
		pair.first = vector[i];
		pair.second = vector[i + 1];
		if (vector[i] < vector[i + 1])
			std::swap(pair.first, pair.second);
		tmp.push_back(pair);
	}

	mergeSort(tmp, 0, len / 2);

	std::vector<int> main, pending;
	for (size_t i = 0; i < len / 2; i++)
	{
		main.push_back(tmp[i].first);
		pending.push_back(tmp[i].second);
	}

	insertSort(main, pending, last);
	
	for (size_t i = 0; i < len; i++)
		vector[i] = main[i];

	vectorTime = (double)(clock() - startTime);
}

void	PmergeMe::mergeSort(std::vector< std::pair<int, int> > &arr, size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t mid = start + (end - start) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid, end);

		std::vector< std::pair<int, int> > sorted(end - start);

		size_t i = start, j = mid, k = 0;
		while (i < mid && j < end)
		{
			if (arr[i].first < arr[j].first)
				sorted[k++] = arr[i++];
			else
				sorted[k++] = arr[j++];
		}
		while (i < mid)
			sorted[k++] = arr[i++];
		while (j < end)
			sorted[k++] = arr[j++];
		
		for (k = 0, i = start; i < end; i++, k++)
			arr[i] = sorted[k];
	}
}

size_t	PmergeMe::binarySearch(std::vector<int> &arr, size_t start, size_t end, int target)
{
	if (end <= start)
		return end;

	size_t mid = start + (end - start) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] < target)
		return binarySearch(arr, mid + 1, end, target);
	else
		return binarySearch(arr, start, mid, target);
}

void	PmergeMe::insertSort(std::vector<int> &main, std::vector<int> &pending, int last)
{
	size_t jacob1 = 1, jacob2 = 1;
	size_t i = 0, index, pendSize = pending.size();
	
	main.insert(main.begin(), pending[0]);	
	while (i < pendSize)
	{
		if (i == jacob1 - 1)
		{
			if (jacob2 >= pendSize)
				break;

			size_t tmp = jacob2;
			jacob2 = jacob2 + (jacob1 * 2);
			jacob1 = tmp;

			if (jacob2 > pendSize)
				i = pendSize - 1;
			else
				i = jacob2 - 1;
		}
		index = binarySearch(main, 0, main.size(), pending[i]);
		main.insert(main.begin() + index, pending[i]);
		i--;
	}
	if (last)
	{
		index = binarySearch(main, 0, main.size(), last);
		main.insert(main.begin() + index, last);
	}
}

void	PmergeMe::sortDeque()
{
	startTime = clock();
	
	size_t len = deque.size();
	if (len < 2)
		return ;
	
	int last = 0;
	if (len % 2 != 0)
		last = deque[len - 1];

	std::deque< std::pair<int, int> > tmp;
	for (size_t i = 0; i + 1 < len; i += 2)
	{
		std::pair<int, int> pair;
		pair.first = deque[i];
		pair.second = deque[i + 1];
		if (deque[i] < deque[i + 1])
			std::swap(pair.first, pair.second);
		tmp.push_back(pair);
	}

	mergeSort(tmp, 0, len / 2);

	std::deque<int> main, pending;
	for (size_t i = 0; i < len / 2; i++)
	{
		main.push_back(tmp[i].first);
		pending.push_back(tmp[i].second);
	}

	insertSort(main, pending, last);
	
	for (size_t i = 0; i < len; i++)
		deque[i] = main[i];

	dequeTime = (double)(clock() - startTime);
}

void	PmergeMe::mergeSort(std::deque< std::pair<int, int> > &arr, size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t mid = start + (end - start) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid, end);

		std::deque< std::pair<int, int> > sorted(end - start);

		size_t i = start, j = mid, k = 0;
		while (i < mid && j < end)
		{
			if (arr[i].first < arr[j].first)
				sorted[k++] = arr[i++];
			else
				sorted[k++] = arr[j++];
		}
		while (i < mid)
			sorted[k++] = arr[i++];
		while (j < end)
			sorted[k++] = arr[j++];
		
		for (k = 0, i = start; i < end; i++, k++)
			arr[i] = sorted[k];
	}
}

size_t	PmergeMe::binarySearch(std::deque<int> &arr, size_t start, size_t end, int target)
{
	if (end <= start)
		return end;

	size_t mid = start + (end - start) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] < target)
		return binarySearch(arr, mid + 1, end, target);
	else
		return binarySearch(arr, start, mid, target);
}

void	PmergeMe::insertSort(std::deque<int> &main, std::deque<int> &pending, int last)
{
	size_t jacob1 = 1, jacob2 = 1;
	size_t i = 0, index, pendSize = pending.size();
	
	main.insert(main.begin(), pending[0]);	
	while (i < pendSize)
	{
		if (i == jacob1 - 1)
		{
			if (jacob2 >= pendSize)
				break;

			size_t tmp = jacob2;
			jacob2 = jacob2 + (jacob1 * 2);
			jacob1 = tmp;

			if (jacob2 > pendSize)
				i = pendSize - 1;
			else
				i = jacob2 - 1;
		}
		index = binarySearch(main, 0, main.size(), pending[i]);
		main.insert(main.begin() + index, pending[i]);
		i--;
	}
	if (last)
	{
		index = binarySearch(main, 0, main.size(), last);
		main.insert(main.begin() + index, last);
	}
}

void	printError()
{
	std::cout << "Error" << std::endl;
	exit(1);
}
