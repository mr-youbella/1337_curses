#include "Span.hpp"
#include <limits>

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_storage = other._storage;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_storage.size() >= _n)
		throw FullException();
	_storage.push_back(number);
}

long	Span::shortestSpan()
{
	if (_storage.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = _storage;
	std::sort(sorted.begin(), sorted.end());
	long min_diff = std::numeric_limits<long>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		long diff = static_cast<long>(sorted[i+1]) - sorted[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return (min_diff);
}

const char	*Span::FullException::what() const throw()
{
	return ("Span is already full");
}

const char	*Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers to find a span");
}

long Span::longestSpan()
{
	if (_storage.size() < 2)
		throw NoSpanException();
	int min_val = *std::min_element(_storage.begin(), _storage.end());
	int max_val = *std::max_element(_storage.begin(), _storage.end());
	return (static_cast<long>(max_val) - min_val);
}

Span::~Span() {}
