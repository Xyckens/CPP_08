Span::Span()
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
	if (this = &other)
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

}

unsigned int	Span::longestSpan()
{

}

void	Span::addNumber(unsigned int last)
{
	try
	{
		if (stored.size() >= n)
			throw Span::SpanAlreadyFullException();
		else
			store.push_back(last);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
}

const char* Span::SpanAlreadyFullException::what() const throw()
{
	return "There are already " << n << " elements stored.\n";
}
