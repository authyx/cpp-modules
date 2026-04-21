#include "PmergeMe.hpp"
#include <ctime>
#include <iterator>
#include <sstream>
#include <limits>
#include <cstdlib>

namespace
{
	std::vector<size_t> buildJacobsthalOrder(size_t count)
	{
		std::vector<size_t> order;

		if (count == 0)
			return order;
		order.push_back(0);
		if (count == 1)
			return order;

		size_t previous = 1;
		size_t current = 3;
		while (order.size() < count)
		{
			size_t upper = current;
			if (upper > count)
				upper = count;
			while (upper > previous)
			{
				order.push_back(upper - 1);
				--upper;
			}
			size_t next = current + (previous * 2);
			previous = current;
			current = next;
		}
		return order;
	}

	bool parsePositiveInt(const std::string &token, int &value)
	{
		std::istringstream iss(token);
		long number;
		char extra;

		if (!(iss >> number))
			return false;
		if (iss >> extra)
			return false;
		if (number <= 0 || number > std::numeric_limits<int>::max())
			return false;
		value = static_cast<int>(number);
		return true;
	}

	template <typename Container>
	void sortFordJohnson(Container &arr)
	{
		if (arr.size() <= 1)
			return;

		typename Container::value_type straggler = 0;
		bool hasStraggler = false;
		if (arr.size() % 2 != 0)
		{
			straggler = arr.back();
			arr.pop_back();
			hasStraggler = true;
		}

		typedef typename Container::value_type value_type;
		std::vector<std::pair<value_type, value_type>> pairs;
		Container largers;

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

		sortFordJohnson(largers);

		Container main;
		Container pending;

		for (size_t i = 0; i < largers.size(); ++i)
		{
			for (typename std::vector<std::pair<value_type, value_type>>::iterator it = pairs.begin();
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

		std::vector<size_t> order = buildJacobsthalOrder(pending.size());
		for (size_t i = 0; i < order.size(); ++i)
		{
			size_t index = order[i];
			typename Container::iterator partnerPos =
				std::find(main.begin(), main.end(), largers[index]);
			typename Container::iterator insertPos =
				std::lower_bound(main.begin(), partnerPos, pending[index]);
			main.insert(insertPos, pending[index]);
		}

		if (hasStraggler)
		{
			typename Container::iterator pos =
				std::lower_bound(main.begin(), main.end(), straggler);
			main.insert(pos, straggler);
		}

		arr = main;
	}

}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{
}
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
		std::cout << _vec[i];
		if (i + 1 < _vec.size())
			std::cout << ' ';
	}
	std::cout << std::endl;
}
void PmergeMe::printDeque() const
{
	for (size_t i = 0; i < _deq.size(); ++i)
	{
		std::cout << _deq[i];
		if (i + 1 < _deq.size())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");
	for (int i = 1; i < argc; ++i)
	{
		int num;
		if (!parsePositiveInt(argv[i], num))
			throw std::runtime_error("Error");

		std::vector<int>::iterator it = std::find(_vec.begin(), _vec.end(), num);
		if (it != _vec.end())
		{
			throw std::runtime_error("Error");
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
	sortFordJohnson(arr);
}

void PmergeMe::_sortDeque(std::deque<int> &arr)
{
	sortFordJohnson(arr);
}