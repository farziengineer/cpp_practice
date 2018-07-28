#include <bits/stdc++.h>
using namespace std;

int dfs(int cur_steps, int residue, vector<int> &given_weights, vector<int> &seq_weights, int steps )
{
	if(seq_weights.size() == steps)
		{
			for(int i = 0; i < seq_weights.size(); i +=1)
				cout<<seq_weights[i]<<" ";
			cout<<endl;
			return 1;
		}


	for(int i = 0; i < given_weights.size(); i +=1)
	{
		if(given_weights[i] > residue and ( seq_weights.empty() or given_weights[i] != seq_weights.back()) )
		{
			seq_weights.push_back(given_weights[i]);
			dfs(cur_steps + 1, given_weights[i] - residue, given_weights, seq_weights, steps);
			seq_weights.pop_back();
		}
	}

	return 0;
}

int main()
{

	vector<int> seq_weights, given_weights;
	int N, x, steps;
	cin>>N;

	for(int i = 0; i < N; i +=1)
	{
		cin>>x;
		given_weights.push_back(x);
	}

	cin>>steps;

	if(dfs(0, 0, given_weights, seq_weights, steps))
	{
		for(int i = 0; i < seq_weights.size(); i +=1)
		{
			cout<<seq_weights[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}