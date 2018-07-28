#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	queue<string> q;
	string val  = "";
	for(int i = 0; s[i]; i +=1)
	{
		if(s[i] != ',')
		{
			val = val + s[i];
		}
		else
		{
			q.push(val);
			val = "";
		}
	}

	if(val!="")
		q.push(val);
	while(q.size()){
		cout<<q.front()<<endl;
		q.pop();
	}

	return 0; 
}