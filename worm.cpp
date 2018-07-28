#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int r, int c)
{
	if(i >= 0 and i < r and j >= 0 and j < c)
		return true;
	return false;
}

void dfs(int i, int j, vector<vector<int> > &grid, vector<vector<bool> > &visited, vector<int> &dx, vector<int> &dy)
{
	if(grid[i][j] == 0)
		return;

	visited[i][j] = true;

	for(int x = 0; x < dx.size(); x +=1)
	{
		for(int y = 0; y < dy.size(); y +=1)
		{	
			if(x == 0 and y == 0)
				continue;
			if(valid(i + dx[x], j + dy[y], grid.size(), grid[0].size()) and visited[i + dx[x]][j + dy[y]] == false)
				dfs(i + dx[x], j + dy[y], grid, visited, dx, dy);
		}
	}

}

int main()
{
	int r, c;
	cin>>r>>c;

	vector<vector<int> > grid (r, vector<int> (c, 0));

	for(int i = 0; i < r; i +=1)
	{
		for(int j = 0; j < c; j +=1)
		{
			cin>>grid[i][j];
		}
	}

	vector< vector<bool> > visited (r, vector<bool> (c, false));
	vector<int> dx = {0, -1, 1};
	vector<int> dy = {0, -1, 1};

	for(int i = 0; i < r; i +=1)
	{
		for(int j = 0; j < c; j +=1)
		{
			if(grid[i][j] == 3)
			{
				dfs(i, j, grid, visited, dx, dy);
			}
		}
	}

	int worm_free = 0;
	for(int i =0 ; i < r; i +=1)
	{
		for(int j = 0; j < c; j +=1)
		{
			if(visited[i][j] == false and grid[i][j] == 1)
				worm_free +=1;
		}
	}

	cout<<worm_free;

	return 0;
}