#ifndef SPAN_HPP
# define SPAN_HPP


# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
private:
	unsigned int n;
	std::vector<int> stored;
	Span();

public:
	Span(unsigned int N);
	Span(Span const &other);
	Span& operator=(Span const &other);
	~Span();

	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			addNumber(unsigned int last);

	class SpanAlreadyFullException: public std::exception
	{
	public:
		const char* what() const throw();
	}
};

#endif