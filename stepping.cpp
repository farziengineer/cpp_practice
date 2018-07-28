// #include <stdio.h>
#include <bits/stdc++.h>
// #include <queue>
using namespace std;
int bfs(int src, int n, int m)
{
    queue<int> que;
    
    int cnt = 0;
    que.push(src);
    
    while(!que.empty())
    {
        int parent = que.front();
        que.pop();
        
        if(parent == 0 or (parent > m ))
            continue;
        
        if(parent >=n and parent <= m)
            cnt +=1;
        
        int choice_1 = parent * 10 + parent % 10 - 1;
        int choice_2 = parent * 10 + parent % 10 + 1;
        
        if(parent % 10 == 0)
            que.push(choice_2);
        
        else if(parent % 10 == 9)
            que.push(choice_1);
            
        else
        {
            que.push(choice_1);
            que.push(choice_2);
        }
    }
    return cnt;
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    int cnt = 0;
	    for(int i = 0; i <= 9; i +=1)
	    {
	        cnt += bfs(i, n, m);
	    }
	    if(n == 0)
            cnt +=1;
	    cout<<cnt<<endl;
	}
	return 0;
}