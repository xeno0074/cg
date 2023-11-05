// https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> stk;        // stack to store next greater element
        vector<int> nextGt(n); // store next greater element

        for (int i = 2 * n - 1; i >= 0; --i)
        {
            while (!stk.empty())
            {
                if (nums[i % n] < stk.top())
                {
                    nextGt[i % n] = stk.top();
                    break;
                }
                else
                {
                    stk.pop();
                }

                if (stk.empty())
                {
                    nextGt[i % n] = -1;
                }
            }

            stk.push(nums[i % n]);
        }

        return nextGt;
    }

#if 0
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> stk; // stack to store indices of next greater element
        vector<int> nextGt(n);

        for (int i = 2 * n - 1; i >= 0; --i)
        {
            while (!stk.empty())
            {
                if (nums[i % n] < nums[stk.top()])
                {
                    nextGt[i % n] = stk.top();
                    break;
                }
                else
                {
                    stk.pop();
                }
            }

            stk.push(i % n);
        }

        return nextGt;
    }
#endif
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