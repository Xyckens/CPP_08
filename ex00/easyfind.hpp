#ifndef EASYFIND_HPP
# define EASYFIND_HPP


# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>

// https://cplusplus.com/reference/algorithm/find/

class ValueNotFoundException:public std::exception
{
public:
	const char* what() const throw() {return "Couldn't find the value!\n";}
};

template <typename T>
typename T::iterator	easyfind(T& tainer, int n)
{
	typename T::iterator it = std::find(tainer.begin(), tainer.end(), n); //find is an algorithm
	if (it != tainer.end())
	{
		std::cout << "Found value: " << n << "!\n";
		return (it);
	}
	throw ValueNotFoundException();
};

#endif