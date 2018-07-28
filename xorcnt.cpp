#include <bits/stdc++.h>
using namespace std;

int cntBits(vector<int> &A) {
    
    int ones = 0, zers = 0, total_diff = 0;
    int mod = 1000000007;
    // int j = 0;
    for(int j = 0; j <= 1; j +=1)
    {
        cout<<"a";
        ones = zers = 0;
        for(int i = 0; i < A.size(); i +=1)
        {
            ones = (ones) + ((A[i]) & 1);
            A[i] = A[i] / 2;
        }
        zers = A.size() - ones;
        total_diff = (total_diff % mod) + ((ones % mod) * (zers % mod)) % mod;
        total_diff = (total_diff % mod);
    }
    
    return total_diff % mod;
}

int main()
{
    vector<int> vec ; vec.push_back(1); vec.push_back(3); vec.push_back(5);
    cout<<cntBits(vec);
    return 0;
}