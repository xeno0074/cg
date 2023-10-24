//-----------------------------------------------------------------------
// https://leetcode.com/problems/global-and-local-inversions/description/
//-----------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector<int> bit;
int n;

void add(int r, int x)
{
    for (; r < n; r = r | (r + 1))
    {
        bit[r] += x;
    }
}

int sum(int r)
{
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
    {
        ret += bit[r];
    }

    return ret;
}

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        n = nums.size();
        bit.resize(n);
        bit.assign(n, 0);

        lli giCnt = 0;
        lli liCnt = 0;

        int j = n - 2;
        for (int i = n - 1; i >= 0; --i)
        {
            giCnt += sum(nums[i] - 1);
            add(nums[i], 1);

            if (j < 0)
            {
                continue;
            }
            if (nums[j] > nums[j + 1])
            {
                ++liCnt;
            }
            --j;
        }

        cout << giCnt << endl;
        cout << liCnt << endl;

        return (liCnt == giCnt);
    }
};

int main()
{
    vector<int> A{0, 1};

    Solution s;

    if (s.isIdealPermutation(A))
    {
        cout << "Right answer\n";
    }
}