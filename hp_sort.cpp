#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// try catch in c++




void max_heapsify(int indx, vector<int> &heaps)
{
	int le = 2*indx + 1;
	int ri = 2*indx + 2;
	int largest = indx;

	if(le < heaps.size() and heaps[le] > heaps[largest])
		largest = le;

	if(ri < heaps.size() and heaps[ri] > heaps[largest])
		largest = ri;

	if(largest != indx)
	{
		int temp = heaps[largest];
		heaps[largest] = heaps[indx];
		heaps[indx] = temp;
		max_heapsify(largest, heaps);
	}	
}

int return_max(vector<int> &heaps)
{
	return heaps[0];
}

void pop_max(vector<int> &heaps)
{
	int temp = heaps.back();
	heaps.back() = heaps[0];
	heaps[0] = temp;
	heaps.pop_back();
	max_heapsify(0, heaps);
}

void build_max_heaps(vector<int> &heaps)
{
	int len = heaps.size() - 1;

	for(int i = len / 2; i >=0; i -=1)
	{
		max_heapsify(i, heaps);
	}
}

void insert_new(int val, vector<int> &heaps)
{
	heaps.push_back(val);
	int indx = heaps.size() - 1;
	while(indx >= 1 and heaps[indx] > heaps[indx / 2])
	{
		int temp = heaps[indx];
		heaps[indx] = heaps[indx/2];
		heaps[indx/2] = temp;

		indx = indx / 2;
	}

}

// void increase_val(int indx, int val,  vector<int> &heaps)
// {
// 	A[indx] = val;

// 	while(indx >=1 and A[indx] > A[indx / 2])
// 	{
// 		int temp = A[indx];
// 		A[indx] = A[indx / 2];
// 		A[indx / 2] = temp;

// 		indx = indx / 2;
// 	}
// }

void decrease_val(vector<int> &heaps)
{

}

int main()
{

	int n;
	cin>>n;
	vector<int> heaps (n, 0), sorted;

	for(int i = 0; i < n; i +=1)
	{
		cin>>heaps[i];
	}

	build_max_heaps(heaps);

	int x;

	for(int i = 1; i <= 5; i +=1){
		cin>>x;
		insert_new(x, heaps);
	}

	int r = heaps.size();

	for(int i = 0; i < r; i +=1)
	{
		sorted.push_back(return_max(heaps));
		pop_max(heaps);
	}

	for(int i = 0; i < sorted.size(); i +=1)
		cout<<sorted[i]<<" ";
	// int x;
	// cin>>x;
	// increase_val(heaps.size() - 1, x, heaps);

	return 0;
}