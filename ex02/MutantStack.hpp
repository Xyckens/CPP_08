#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
#include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack(): std::stack<T>() {std::cout << "MutantStack Constructor called\n"; };
	MutantStack(const MutantStack<T>& other): std::stack<T>(other) {std::cout << "MutantStack Constructor called\n";};
	MutantStack	&operator=(const MutantStack<T>& other)
	{
		if (this == &other)
			return (*this);
		std::stack<T>::operator=(other);
		return (*this);
	};
	~MutantStack() {std::cout << "MutantStack Destructor called\n"; };

	typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	//member Container: c the underlying container (protected member object)
	
    iterator begin() {return (this->c.begin()); };

    iterator end() {return (this->c.end()); };

    const_iterator begin() const {return (this->c.begin()); };

    const_iterator end() const {return (this->c.end()); };

    reverse_iterator rbegin() {return (this->c.rbegin()); };

    reverse_iterator rend() {return (this->c.rend()); };

    const_reverse_iterator rbegin() const {return (this->c.rbegin()); };

    const_reverse_iterator rend() const {return (this->c.rend()); };
};

#endif
