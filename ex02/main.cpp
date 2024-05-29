#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

  	std::cout << "\n---Iterator---" << std::endl;
	for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << std::endl;

	//std::stack<int> s(mstack);

	std::cout << "\n--- Reverse iterator ---" << std::endl;

	MutantStack<std::string> rev;

	rev.push("one");
	rev.push("two");
	rev.push("three");
	rev.push("four");
	rev.push("five");

	for (MutantStack<std::string>::reverse_iterator rev_itr = rev.rbegin(); rev_itr != rev.rend(); rev_itr++)
		std::cout << *rev_itr << std::endl;

	std::cout << "\n---Const Iterator---" << std::endl;
	for(MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << std::endl;

	//std::stack<int> s(mstack);

	std::cout << "\n--- Const Reverse iterator ---" << std::endl;

	for (MutantStack<std::string>::const_reverse_iterator rev_itr = rev.rbegin(); rev_itr != rev.rend(); rev_itr++)
		std::cout << *rev_itr << std::endl;

	std::cout << "\n--- Copy constructor ---" << std::endl;

	MutantStack<int> copy(mstack);

	copy.pop();
	copy.pop();
	copy.pop();
	copy.push(64);
	copy.push(65);
	copy.push(66);

	for (MutantStack<int>::iterator copy_itr = copy.begin(); copy_itr != copy.end(); copy_itr++)
		std::cout << *copy_itr << std::endl;

	std::cout << "\n--- Assignment operator ---" << std::endl;
	MutantStack<int> a_copy;
	a_copy = mstack;

	a_copy.pop();
	a_copy.pop();
	a_copy.pop();
	a_copy.push(128);
	a_copy.push(129);
	a_copy.push(130);

	for (MutantStack<int>::iterator a_copy_itr = a_copy.begin(); a_copy_itr != a_copy.end(); a_copy_itr++)
		std::cout << *a_copy_itr << std::endl;
	return 0;
}