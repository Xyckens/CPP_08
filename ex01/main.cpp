
#include "Span.hpp"

int main()
{
	{
		std::cout << "\t\tSmall Span\n";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);

		std::cout << "\n----Testing add number when the span is full----\n";
			sp.addNumber(30);
			sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan()<< std::endl;
	}
	{
		std::cout << "\t\tBig Span\n";
		Span big_sp = Span(20000);
		std::vector<unsigned int> nums(20000);
		srand(time(0));
    	for (unsigned int i = 0; i < 20000; ++i)
		{
        	nums[i] = i * rand();
		}
		big_sp.addMultNumbers(nums.begin(), nums.end());
		std::cout << "Shortest span: " << big_sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << big_sp.longestSpan()<< std::endl;

		std::cout << "\t\tCopy test\n";
		Span big_sp2 = Span(20000);
		
		big_sp2 = big_sp;
		
		std::cout << "Shortest span: " << big_sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << big_sp2.longestSpan()<< std::endl;

		Span big_sp3(big_sp2);
		std::cout << "Shortest span: " << big_sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << big_sp3.longestSpan()<< std::endl;
	}
}