#include "Span.hpp"
#include <climits>
#include <stdexcept>

void Span::addNumber(int number)
{
	if (vec.size() >= _N)
		throw std::out_of_range("Span is full");
	vec.push_back(number);
}

int Span::shortestSpan() const
{
	if (vec.size() < 2)
		throw std::logic_error("Not enough elements to calculate span");

	std::vector<int> sorted(vec);
	std::sort(sorted.begin(), sorted.end());

	int minSpan = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (vec.size() < 2)
		throw std::logic_error("Not enough elements to calculate span");

	std::vector<int>::const_iterator minIt = std::min_element(vec.begin(), vec.end());
	std::vector<int>::const_iterator maxIt = std::max_element(vec.begin(), vec.end());

	return *maxIt - *minIt;
}

Span::Span()
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &other) : _N(other._N), vec(other.vec)
{
}

Span &Span::operator=(const Span &other)
{
	(this)->vec = other.vec;
	(this)->_N = other._N;
	return *this;
}

Span::~Span()
{
}