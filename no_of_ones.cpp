// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>

int main()
{
	int n, ones = 0;
	std::cin>>n;

	while(n)
	{
		 ones = ones + abs(n) % 2 ; 
		 n = n / 2;
	}

	std::cout<< ones << std::endl;

	return 0;
}