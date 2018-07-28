#include <bits/stdc++.h>
using namespace std;

int sear[1004], cp[1005], dp[1005];

int cp_paste(int i, int n, int k)
{
	if(i == n-1)
		return min(cp[i], sear[i]);

	if(i >= n)
		return 0;

	if(dp[i] != -1)
		return dp[i];

	int choice_1 = cp[i] + cp_paste(i + 1, n, k);
	int choice_2 = 1000000;

	for(int indx = i + 1; indx < i + k; indx ++)
	{
		choice_2 = min(choice_2, cp_paste(indx, n, k));
	}

	dp[i] = min(sear[i] +choice_2, choice_1) ;
	return dp[i];
}

int main()
{
	int n, k;

	for(int i = 0; i < 1003; i++)
	{
		dp[i] = -1;
	}
	cin>>n>>k;

	for(int i = 0; i < n; i ++)
	{
		cin>>cp[i];
	}

	for(int i = 0; i < n; i ++)
	{
		cin>>sear[i];
	}

	cout<<cp_paste(0, n, k)<<endl;


	return 0 ;
}