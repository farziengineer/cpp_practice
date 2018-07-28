#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	int level;
};

int solve(int x, int y)
{
	queue<Node> que;
	set<int> fre;
	Node a;
	a.val = x, a.level = 0;

	que.push(a);
	while(!que.empty())
	{
		Node temp = que.front();
		que.pop();

		if(temp.val == y)
			return temp.level;

		if(fre.find(temp.val * 2) == fre.end())
		{
			Node choice_1;
			choice_1.val = temp.val * 2;
			choice_1.level = temp.level + 1;
			que.push(choice_1);
		}

		fre.insert(temp.val * 2);

		if(temp.val - 1 > 0 and fre.find(temp.val - 1) == fre.end())
		{
			Node choice_2;
			choice_2.val = temp.val - 1;
			choice_2.level = temp.level + 1;
			que.push(choice_2);
		}
	}	
}

int main()
{
	int x, y;
	cin>>x>>y;

	cout<<solve(x, y);
}