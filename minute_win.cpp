

#include <bits/stdc++.h>
using namespace std;

int recur(int i, int prev_modified, int k, vector<int> &vec, vector<int> &before)
{
	if(i == vec.size())
		return 0;

	int choice_1 = 100000, choice_2 = 100000, choice_3 = 100000;

	choice_1 = before[i - 1] + recur(i + 1, 0, k, vec, before);

	if(prev_modified == 1)
	{
		choice_2 = recur(i + 1, 0, k, vec, before);
	}
	else
	{
		choice_3 = !(vec[i] - vec[i - 1] == k) + recur(i + 1, !(vec[i] - vec[i - 1]), vec, before);
	}

	return min( choice_1, min(choice_2, choice_3));
}

int main()
{

	int n, k, a;
	cin>>n>>k;

	vector<int> a;
	for(int i = 0; i < n; i +=1)
	{
		cin>>a;
		vec.push_back(a);
	}

	int ans = min(recur(0, 0, a, before), recur(0, 1, a, before));

	cout<<ans;

	return 0;
}