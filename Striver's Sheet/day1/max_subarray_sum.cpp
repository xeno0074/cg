// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    vector<int> x(n + 1); // prefix sum array of nums
    x[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        x[i] = nums[i - 1] + x[i - 1];
    }

    int i = 0;
    int j = 1;
    int maxdiff = x[0];

    while (j <= n)
    {

        if (x[j] >= x[j - 1])
        {
            maxdiff = max(maxdiff, x[j] - x[i]);
        }
        else
        {
            if (x[j] <= x[i])
            {
                i = j;
            }
        }

        ++j;
    }

    return maxdiff;
}

int main()
{
    vector<int> v1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2{5, 4, -1, 7, 8};
    vector<int> v3{-2, -1};

    // cout << maxSubArray(v1) << "\n";
    // cout << maxSubArray(v2) << "\n";
    cout << maxSubArray(v3) << "\n";

    return 0;
}