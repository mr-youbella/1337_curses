#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _storage;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int number);
		template <typename T>
		void addRange(T begin, T end)
		{
			if (_storage.size() + std::distance(begin, end) > _n)
				throw std::out_of_range("Span is full");
			_storage.insert(_storage.end(), begin, end);
		}
		long shortestSpan();
		long longestSpan();
		class FullException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		~Span();
};

#endif
