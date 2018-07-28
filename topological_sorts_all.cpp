#include <bits/stdc++.h>
using namespace std;

vector<int> adj[3000];

void dfs(int src, vector<bool> &vis, int lengths, vector<int> &stk)
{
	if(lengths == 0)
	{
		for(i = 0; i < stk.size(); i +=1)
			cout<<stk[i]<<" ";
		cout<<endl;
	}

	vis[src] = true;

	for(int i = 0; i < adj[src].size(); i +=1)
	{
		if(vis[adj[src][i]] == false)
		{
			dfs(adj[src][i], vis, lengths - 1, stk);
		}
	}

	stk.push_back(src);
}


int main()
{
	int edges, x, y;

	cin>>edges;

	for(int i = 1; i <= edges; i +=1)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}

	vector<bool> vis (nodes, false);

	for(int i = 0; i < nodes; i +=1)
	{
		if(vis[i] == false)
		{
			vector<int> stk;
			dfs(i, vis, nodes, stk);
		}
	}

	return 0;
}