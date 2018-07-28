#include <iostream>
using namespace std;


int main()
{
	// int mohit = 32;
	#ifndef mohit
		int a;
		cin>>a;
		#define mohit 32;
		// int MOHIT = 1;


	#else
		cout<<a<<endl;

	#endif

	return 0;
}