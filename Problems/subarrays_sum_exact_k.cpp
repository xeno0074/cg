#include <bits/stdc++.h>

using namespace std;

int sol(vector<int> &nums, const int k)
{
    int n = nums.size();
    int curr = 0;
    int ret = 0;
    unordered_map<int, int> prefixCount;

    // insert the initial prefix
    prefixCount[0] = 1; // (sum till index 0) = 0 exist once

    for (int num : nums)
    {
        curr += num;
        ret += prefixCount[curr - k];
        prefixCount[curr]++;
    }

    return ret;
}

int main()
{
    vector<int> nums{1, 2, 1, 2, 1};
    int k = 3;

    cout << sol(nums, k) << endl;
}