#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
};

int main()
{
	Node* x = new Node;
	x->data = 5;
	cout<<x->data;
	return 0;
}