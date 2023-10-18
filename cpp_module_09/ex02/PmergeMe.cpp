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
		vector.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		vector = obj.vector;
		list = obj.list;
		startTime = obj.startTime;
		vectorTime = obj.vectorTime;
		listTime = obj.listTime;
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
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << listTime << " us" << std::endl;
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
		if (vector[i] < vector[i + 1])
		{
			pair.first = vector[i + 1];
			pair.second = vector[i];
		}
		else
		{
			pair.first = vector[i];
			pair.second = vector[i + 1];
		}
		tmp.push_back(pair);
	}

	mergeSort(tmp, 0, len / 2);

	std::vector<int> main, pending;
	for (size_t i = 0; i < len / 2; i++)
	{
		main.push_back(tmp[i].first);
		pending.push_back(tmp[i].second);
	}

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
	
	for (i = 0; i < len; i++)
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

		std::vector< std::pair<int, int> > ret(end - start);

		size_t i = start, j = mid, k = 0;
		while (i < mid && j < end)
		{
			if (arr[i].first < arr[j].first)
				ret[k++] = arr[i++];
			else
				ret[k++] = arr[j++];
		}
		while (i < mid)
			ret[k++] = arr[i++];
		while (j < end)
			ret[k++] = arr[j++];
		
		for (k = 0, i = start; i < end; i++, k++)
			arr[i] = ret[k];
	}
}

size_t	PmergeMe::binarySearch(std::vector<int> result, size_t start, size_t end, int target)
{
	if (end <= start)
		return end;

	size_t mid = start + (end - start) / 2;

	if (result[mid] == target)
		return mid;
	else if (result[mid] < target)
		return binarySearch(result, mid + 1, end, target);
	else
		return binarySearch(result, start, mid, target);
}

void	PmergeMe::sortList()
{
	startTime = clock();
	
	// sort

	listTime = (double)(clock() - startTime);
}

void	printError()
{
	std::cout << "Error" << std::endl;
	exit(1);
}
