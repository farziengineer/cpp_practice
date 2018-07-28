#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int find_pivot(int le, int ri, vector<int> &vec)
{
	int j = le - 1;
	int temp;
	for(int i = le ; i < ri; i +=1)
	{
		if(vec[i] <= vec[ri])
		{
			j +=1;
			temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	j +=1;
	temp = vec[j];
	vec[j] = vec[ri];
	vec[ri] = temp;

	return j;

}



void quick_sort(int le, int ri, vector<int> &vec)
{
	// if(ri <= le)
	// 	return;
	if(ri - le == 0)
		return;
	if(ri >= vec.size() or le >= vec.size() or ri < 0 or le < 0 or ri < le)
		return;
	cout<<le<<" "<<ri<<endl;

	int pivot_indx = find_pivot(le, ri, vec);
	quick_sort(le, pivot_indx - 1, vec);
	quick_sort(pivot_indx + 1, ri, vec);
}




int main()
{
	int n;
	cin>>n;
	vector<int> vec (n, 0);

	for(int i = 0; i < n; i +=1)
	{
		cin>>vec[i];
		// vec.push_back()
	}

	quick_sort(0, vec.size() - 1, vec);

	for(int i = 0; i < vec.size(); i +=1)
	{
		cout<<vec[i]<<" ";
	}

	cout<<endl;

	return 0;
}