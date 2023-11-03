// https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <bits/stdc++.h>

using namespace std;

int countGoodArrays(vector<int> v, int k)
{
    if (k == 0)
    {
        return 0;
    }

    int count = 0;

    unordered_map<int, int> mp;

    mp[v[0]]++;

    for (int i = 0, j = 1; i < j; ++j)
    {
        mp[v[j]]++;
    }

    return count;
}

int main()
{
    vector<int> v{1, 2, 1, 2, 3};

    cout << countGoodArrays(v, 2) << "\n";
}