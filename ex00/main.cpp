#include "easyfind.hpp"

int	main(void)
{
	int c[5] = {1, 2, 3, 4, 5};
	std::vector<int> vec(c, c + 5);
	std::cout << "\t\tVectors:\n";
	try
	{
		easyfind(vec, 5);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		easyfind(vec, 2);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		easyfind(vec, -10);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::deque<int> queue(c, c + 5);
	std::cout << "\t\tQueues:\n";

	try
	{
		easyfind(queue, 5);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}

	try
	{
		easyfind(queue, 2);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		easyfind(queue, -10);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
}