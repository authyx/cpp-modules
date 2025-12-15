#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <algorithm>
#include <vector>

class Span
{
private:
Span();

unsigned int _N;
std::vector<int> vec;

public:
	// Orthodox Canonical Form
	Span(const Span &other);
	Span(unsigned int);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int);
	int shortestSpan() const;
	int longestSpan() const;
	template <typename Iterator> void addRange(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
	{
		addNumber(*it);
	}
}

#endif