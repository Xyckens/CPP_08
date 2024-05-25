
#include "Span.hpp"

Span::Span(): n(0)
{
	std::cout << "Span Constructor Called.\n";
}

Span::Span(unsigned int N): n(N)
{
	std::cout << "Span Constructor with Max N Defined Called.\n";
}

Span::Span(Span const &other)
{
	n = other.n;
	stored.clear();
	stored = other.stored;
	std::cout << "Span Copy Constructor Called.\n";
}

Span& Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	n = other.n;
	stored.clear();
	stored = other.stored;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span Destructor Called.\n";

}

unsigned int	Span::shortestSpan()
{
	try
	{
		if (n > 1)
		{
			long int min = longestSpan();
			long int span = 0;
			for (std::vector<int>::iterator ptr = stored.begin(); ptr < stored.end(); ptr++)
			{
				for (std::vector<int>::iterator ptr1 = ptr; ptr1 < stored.end(); ptr1++)
				{
					if (ptr == ptr1)
						continue;
					span = std::abs((long)*ptr - (long)*ptr1);
					if (span < min)
						min = span;
				}
			}
			return (min);
		}
		else
			throw Span::SpanNotBigEnoughException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

unsigned int	Span::longestSpan()
{
	try
	{
		if (n > 1)
			return std::abs(*std::max_element(stored.begin(), stored.end()) - *std::min_element(stored.begin(), stored.end()));
		else
			throw Span::SpanNotBigEnoughException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

void	Span::addNumber(unsigned int last)
{
	try
	{
		if (stored.size() >= n)
			throw Span::SpanAlreadyFullException();
		else
			stored.push_back(last);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
}

void	Span::addMultNumbers(const std::vector<unsigned int>::iterator& begin, const std::vector<unsigned int>::iterator& end)
{
	try
	{
		if (std::distance(begin, end) + stored.size() > n )
		{
			stored.insert(stored.end(), begin, begin + (n - stored.size()));
			throw Span::SpanAlreadyFullException();
		}
		else
			stored.insert(stored.end(), begin, end);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
}

const char* Span::SpanAlreadyFullException::what() const throw()
{
	return "This span is already full of elements stored.\n";
}

const char* Span::SpanNotBigEnoughException::what() const throw()
{
	return "There are not enough elements stored to calculate span.\n";
}