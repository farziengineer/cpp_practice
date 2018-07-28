#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	string zer = "ZERO";
	int error = 0;

	cin>>str;

	for(int i = 0; str[i] != '\0'; i += 1)
	{
		if(str[i] != zer[i % 4])
			error +=1;
	}
	cout<<error;

	return 0;
}