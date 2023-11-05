//-----------------------------------------------------------------
// https://www.geeksforgeeks.org/inversion-count-in-array-using-bit/
//-----------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------

namespace g
{
    vector<int> ft;
    int N;
}

void add0ft(int l, int delta)
{
    for (; l < g::N; l = l | (l + 1))
    {
        g::ft[l] += delta;
    }
}

int sum0ft(int l)
{
    int ret = 0;
    for (; l >= 0; l = (l & (l + 1)) - 1)
    {
        ret += g::ft[l];
    }
    return ret;
}

int solution0ft(vector<int> nums)
{
    int ret = 0;

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        ret += sum0ft(nums[i]);

        add0ft(nums[i], 1);
    }

    return ret;
}

class Solution
{
public:
    int countInversion(vector<int> nums)
    {
        int maxVal = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            maxVal = max(maxVal, nums[i]);
        }

        g::N = maxVal + 1;
        g::ft.resize(g::N, 0);

        return solution0ft(nums);
    }
};

//-----------------------------------------------------------------
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.countInversion(nums);
        cout << ans << "\n";
    }
    return 0;
}
//-----------------------------------------------------------------
