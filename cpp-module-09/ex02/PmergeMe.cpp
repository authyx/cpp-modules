#include "PmergeMe.hpp"
#include <ctime>
#include <iterator>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}
void PmergeMe::printVector() const
{
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}
void PmergeMe::printDeque() const
{
	for (size_t i = 0; i < _deq.size(); ++i)
	{
		std::cout << _deq[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num <= 0)
		{
			std::cerr << "Error: Non-positive numbers are not allowed." << std::endl;
			exit(EXIT_FAILURE);
		}
		std::vector<int> ::iterator it = std::find(_vec.begin(), _vec.end(), num);
		if (it != _vec.end())
		{
			std::cerr << "Error: Duplicate numbers are not allowed." << std::endl;
			exit(EXIT_FAILURE);
		}
		_vec.push_back(num);
		_deq.push_back(num);
	}
}

long micros()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	long us = (long)ts.tv_sec * 1000000 + (long)ts.tv_nsec / 1000;
	return us;
}

void PmergeMe::runVectorSort()
{
	_sortVector(_vec);
}

void PmergeMe::runDequeSort()
{
	_sortDeque(_deq);
}

void PmergeMe::_sortVector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;
	int straggler = -1;
	if (arr.size() % 2 != 0)
	{
		straggler = arr.back();
		arr.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> largers;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
			largers.push_back(arr[i]);
		}
		else
		{
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
			largers.push_back(arr[i + 1]);
		}
	}

	_sortVector(largers);

	std::vector<int> main;
	std::vector<int> pending;

	for (size_t i = 0; i < largers.size(); ++i)
	{
		for (std::vector< std::pair< int, int > >::iterator it = pairs.begin();
				it != pairs.end(); ++it)
		{
			if (it->second == largers[i])
			{
				main.push_back(it->second);
				pending.push_back(it->first);
				break;
			}
		}
	}

	if (!pending.empty())
		main.insert(main.begin(), pending[0]);

	for (size_t i = 1; i < pending.size(); ++i)
	{
		std::vector< int >::iterator partnerPos =
			std::find(main.begin(), main.end(), largers[i]);
		std::vector< int >::iterator insertPos =
			std::lower_bound(main.begin(), partnerPos, pending[i]);
		main.insert(insertPos, pending[i]);
	}

	if (straggler != -1)
	{
		std::vector< int >::iterator pos =
			std::lower_bound(main.begin(), main.end(), straggler);
		main.insert(pos, straggler);
	}

	arr = main;
}

void PmergeMe::_sortDeque(std::deque< int > &arr)
{
	if (arr.size() <= 1)
		return;
	int straggler = -1;
	if (arr.size() % 2 != 0)
	{
		straggler = arr.back();
		arr.pop_back();
	}
	std::deque< std::pair< int, int > > pairs;
	std::deque< int > largers;
	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
			largers.push_back(arr[i]);
		}
		else
		{
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
			largers.push_back(arr[i + 1]);
		}
	}

	_sortDeque(largers);

	std::deque< int > main;
	std::deque< int > pending;

	for (size_t i = 0; i < largers.size(); ++i)
	{
		for (std::deque< std::pair< int, int > >::iterator it = pairs.begin();
				it != pairs.end(); ++it)
		{
			if (it->second == largers[i])
			{
				main.push_back(it->second);
				pending.push_back(it->first);
				break;
			}
		}
	}

	if (!pending.empty())
		main.insert(main.begin(), pending[0]);

	for (size_t i = 1; i < pending.size(); ++i)
	{
		std::deque< int >::iterator partnerPos =
			std::find(main.begin(), main.end(), largers[i]);
		std::deque< int >::iterator insertPos =
			std::lower_bound(main.begin(), partnerPos, pending[i]);
		main.insert(insertPos, pending[i]);
	}

	if (straggler != -1)
	{
		std::deque< int >::iterator pos =
			std::lower_bound(main.begin(), main.end(), straggler);
		main.insert(pos, straggler);
	}

	arr = main;
}