#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	vectorTime = 0;
	listTime = 0;
	k = 1;
}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->vector = obj.vector;
		this->list = obj.list;
		this->vectorTime = obj.vectorTime;
		this->listTime = obj.listTime;
		this->k = obj.k;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::init(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			if (!isdigit(argv[i][j]))
				printError();
		int value = atoi(argv[i]);
		vector.push_back(value);
		list.push_back(value);
	}
	k = vector.size() / 2;
}

void	PmergeMe::sort()
{
	std::cout << "Before:	";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	vectorSort();
	// listSort();

	std::cout << "After:	";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << listTime << " us" << std::endl;
}

void	PmergeMe::vectorSort()
{
	clock_t start = clock();
	vectorInsertionSort(0, vector.size() - 1);
	clock_t end = clock();
	vectorTime = (end - start) / 1000;
}

void	PmergeMe::vectorMergeInsertionSort(int left, int right)
{
    if (left < right) {
        if (right - left <= k) {
            vectorInsertionSort(left, right);
        } else {
            int mid = left + (right - left) / 2;
            vectorMergeInsertionSort(left, mid);
            vectorMergeInsertionSort(mid + 1, right);
            vectorMerge(left, mid, right);
        }
    }
}

void	PmergeMe::vectorInsertionSort(int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = vector[i];
        int j = i - 1;
        
        while (j >= left && vector[j] > key) {
            vector[j + 1] = vector[j];
            j--;
        }

        vector[j + 1] = key;
    }
}

void	PmergeMe::vectorMerge(int left, int mid, int right)
{
	int n1 = mid - left + 1;
    int n2 = right - mid;

	std::vector<int> L, R;

    for (int i = 0; i < n1; i++) {
        L[i] = vector[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vector[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        } else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vector[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vector[k] = R[j];
        j++;
        k++;
    }
}

void	printError()
{
	std::cout << "Error" << std::endl;
	exit(1);
}
