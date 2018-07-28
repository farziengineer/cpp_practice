#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


void merge(int le, int mid, int ri, vector<int> &vec)
{
	vector<int> left , right;

	for(int i = le; i <= mid; i +=1)
		left.push_back(vec[i]);

	for(int i = mid + 1; i <= ri; i +=1)
		right.push_back(vec[i]);

	int i = 0, j = 0;

	while(i < left.size() or j < right.size())
	{
		if(i < left.size() and j < right.size())
		{
			if(left[i] < right[j])
			{
				vec[le] = left[i];
				i +=1;
			}
			else 
			{
				vec[le] = right[j];
				j +=1;
			}
		}

		else if( i < left.size())
		{
			vec[le] = left[i];
			i +=1;
		}

		else if(j < right.size())
		{
			vec[le] = right[j];
			j +=1;
		}

		le +=1;
	}
}



void merge_sort(int le, int ri, vector<int> &vec)
{
	if(ri - le + 1 == 1)
		return;
	if(ri - le < 1)
		return;
	int mid = le + (ri - le) / 2;

	merge_sort(le, mid, vec);
	merge_sort(mid + 1, ri, vec);
	
	merge(le, mid, ri, vec);
	
}



int main()
{
	int n;
	cin>>n;
	vector<int> vec (n, 0);

	for(int i = 0; i < n; i +=1)
	{
		cin>>vec[i];
	}

	merge_sort(0, vec.size() - 1, vec);

	for(int i = 0;i < vec.size(); i +=1)
	{
		cout<<vec[i]<<" ";
	}

	return 0;
}