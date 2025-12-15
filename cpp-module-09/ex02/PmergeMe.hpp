#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	void _sortVector(std::vector<int> &arr);
	void _sortDeque(std::deque< int > &arr);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseArgs(int argc, char **argv);
	void runVectorSort();
	void runDequeSort();
	void printVector() const;
	void printDeque() const;
};


long micros();

#endif