#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class LRU_Cache
{
	list <int> dq;

	unordered_map<int, list<int>::iterator> present;

	int max_capacity;

	public:
		LRU_Cache(int n)
		{
			max_capacity = n;
		}

		void refer(int x)
		{
			if(present.find(x) == present.end())
			{
				if(dq.size() == max_capacity)
				{
					int least_recently_used = dq.back();
					dq.pop_back();
					present.erase(least_recently_used);
				}

				dq.push_front(x);
				present[x] = dq.begin();
			}
			else
			{
				dq.erase(present[x]);
				present.erase(x);
				dq.push_front(x);
				present[x] = dq.begin();
			} 
		}

		void print_lru()
		{
			for(auto it = dq.begin(); it != dq.end(); ++it)
				cout<<(*it)<<" ";
		}
		

};


int main()
{
    LRU_Cache ca(4);
 
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.print_lru();
 
    return 0;
}