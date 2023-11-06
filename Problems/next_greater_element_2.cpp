// https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> stk;            // stack to store next greater element
        vector<int> nextGt(n, -1); // store next greater element

        for (int i = 2 * n - 1; i >= 0; --i)
        {
            while (!stk.empty() && nums[i % n] >= stk.top())
            {
                stk.pop();
            }
            if (!stk.empty() && i < n)
            {
                nextGt[i] = stk.top();
            }

            stk.push(nums[i % n]);
        }

        return nextGt;
    }
};

void printv(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> v{1, 2, 3, 4, 3};

    Solution sol;

    printv(sol.nextGreaterElements(v));
}