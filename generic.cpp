#include<stdio.h>
#include<iostream>

template <class X, class Y>
bool big(X a, Y b)
{
	return a > b;
}

int main()
{
	
	std::cout<<big(4.5, 5.5)<<'\n';
	std::cout<<big(5.2, 3)<<'\n';	
	return 0;
}