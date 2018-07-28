#include <bits/stdc++.h>
using namespace std;


// Complete the zombieCluster function below.

void zombies_dfs(int i, int j, vector<string> &grid ,vector<vector<bool > > &visited)
{
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or visited[i][j] == 1)
            return ;
        
        if(grid[i][j] == '0')
            return ;
        
        visited[i][j] = 1;
        
        zombies_dfs(i + 1, j, grid, visited);
        zombies_dfs(i, j + 1, grid, visited);
        zombies_dfs(i - 1, j, grid, visited);
        zombies_dfs(i , j - 1, grid, visited);
        

}

int zombieCluster(vector<string> zombies) {
    
    int rw = zombies.size();
    int cl = zombies[0].size();
    int connected = 0;
    
    vector< vector<bool> > visited (zombies.size(), vector<bool> (zombies[0].size(), false));
    
    for(int i = 0; i < rw; i +=1)
    {
        for(int j = 0; j < cl; j +=1)
        {
            if(visited[i][j] == false and zombies[i][j] == '1')
            {
                zombies_dfs(i, j, zombies, visited);
                connected = connected + 1;
            }
        }
    }
    
    return connected;

}

int main()
{
    int n;
    cin>>n;
    string str;
    vector<string> stx;
    for(int i = 0; i < n; i+=1)
    {
        cin>>str;
        stx.push_back(str);
    }

    cout<<zombieCluster(stx);

    return 0;
}