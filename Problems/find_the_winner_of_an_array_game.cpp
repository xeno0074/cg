// https://leetcode.com/problems/find-the-winner-of-an-array-game/

#include <bits/stdc++.h>

using namespace std;

void printv(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

vector<int> getNextBigIndices(const vector<int> &nums)
{
    int n = nums.size();
    stack<int> stk;         // stack to store indices of candidate next greater element
    vector<int> ret(n, -1); // store indices of next greater elements

    for (int i = 2 * n - 1; i >= 0; --i)
    {
        while (!stk.empty() && nums[i % n] >= nums[stk.top()])
        {
            stk.pop();
        }

        if (i < n && !stk.empty())
        {
            ret[i] = stk.top();
        }

        stk.push(i % n);
    }

    return ret;
}

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        vector<int> nextBig = getNextBigIndices(arr);

        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            int winCount = nextBig[i] - i - !i; // any other element must win once already to be in zeroth element
                                                // except for the already zeroth element

            if (winCount >= k || nextBig[i] == -1)
            {
                return arr[i];
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> v1{2, 1, 3, 5, 4, 6, 7};
    int k1 = 2;

    printv(v1);
    cout << sol.getWinner(v1, k1) << endl;

    cout << "==========================\n";
    vector<int> v2{3, 2, 1};
    int k2 = 10;

    printv(v2);
    cout << sol.getWinner(v2, k2) << endl;

    cout << "==========================\n";
    vector<int> v3{1, 9, 8, 2, 3, 7, 6, 4, 5};
    int k3 = 10;

    printv(v3);
    cout << sol.getWinner(v3, k3) << endl;

    return 0;
}