// https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>

using namespace std;

class NumArray
{
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        prefix.resize(n + 1);

        prefix[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right) { return prefix[right + 1] - prefix[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> v{-2, 0, 3, -5, 2, -1};
    NumArray na(v);

    cout << na.sumRange(0, 2) << endl;
    cout << na.sumRange(2, 5) << endl;
    cout << na.sumRange(0, 5) << endl;

    return 0;
}