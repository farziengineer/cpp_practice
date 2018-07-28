#include <bits/stdc++.h>
using namespace std;
// extern int a;

void print_all(vector<int> *ptr)
{
	for(int i = 0; i < (*ptr).size(); i +=1)
	{
		cout<<((*ptr)[0])<<" ";
		// ptr++;
	}
}

void call_me()
{
	int *new_space = new int[1000];
}


int main()
{
	// int a = 0;
	// cout<<a;
	// cout<<"hello";

	// int a[5];
	// cout<<a[7]<<endl;

	// int b[] = {1,2};

	// // for(int i = 0; i < 5; i +=1) cout<<b[i]<<" ";

	// cin>>b[500];
	// cout<<b[5]<<endl;	
	// vector<int> vec (1, 1);
	// cout<<vec.at(0);
	// string s;
	// s = "a" + "b";
	// cout<<s<<endl;

	// int a[5] = {1,2,3,4,5};

	// int *ptr = a;

	// for(int i = 0; i < 5; i +=1) {cout<<(*ptr)++<<" ";}

	// vector<int> vec = {1,2,3,4,67,7};
	// vector<int> *ptr = &vec;

	// print_all(ptr);

	// int arr [5] = {1,2,3,4,5};
	// const int *x = arr;	

	// for(int i = 0; i < 5; i +=1)
	// {
	// 	cout<<(*x)<<" ";
	// 	(x++);
	// }

	// vector<int> vec = {1,2,3 ,5};
	// vector<int> &ptr = vec;
	// for(int i = 0; i < ptr.size(); i +=1)
	// 	cout<<ptr[i]<<" "<<vec[i]<<endl;

	// int arr[] = {1,2,45};
	// int *const x = arr;

	// for(int i  = 0; i < 3; i +=1)
	// {
	// 	cout<<x[i]<<" "<<(*(x + i))<<endl;
	// }

	// memory leak example
	int i = 0 ;
	while(i < 1000000)
	{
		call_me();
		i +=1;
	}

	return 0;
}