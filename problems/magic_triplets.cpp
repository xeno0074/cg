//-----------------------------------------------------------------
// https://practice.geeksforgeeks.org/problems/magic-triplets4003/1
//-----------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------
#define DPRINT

#ifdef DPRINT
void printVec(const vector<int> v, const char header[])
{
    cout << header;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "\n";
}
#endif

class FT
{
    vector<int> ft;
    int n;

public:
    FT(int n)
    {
        this->n = n;
        ft.resize(n, 0);
    }

    void clearResize(int n)
    {
        this->n = n;
        ft.clear();
        ft.resize(n, 0);
    }

    void add(int l, int x)
    {
        for (; l < n; l = l | (l + 1))
        {
            ft[l] += x;
        }
    }

    int sum(int l)
    {
        int ret = 0;
        for (; l >= 0; l = (l & (l + 1)) - 1)
        {
            ret += ft[l];
        }
        return ret;
    }

#ifdef DPRINT
    vector<int> getft()
    {
        return ft;
    }
#endif
};

int solution0ft(int ftsize, vector<int> nums)
{
#ifdef DPRINT
    printVec(nums, "nums - ");
#endif

    int n = nums.size();
    FT ft(ftsize);
    vector<int> lnum(n, 0); // stores number of elements on the left that are less than current
    vector<int> rnum(n, 0); // stores number of elements on the right that are greater than current

    for (int i = 0; i < n; ++i)
    {
#ifdef DPRINTx
        printVec(ft.getft(), "lft - ");
#endif
        lnum[i] += ft.sum(nums[i] - 1);
        if (ft.sum(nums[i]) - lnum[i] == 0) // skip adding same number
        {
            ft.add(nums[i], 1);
        }
    }

#ifdef DPRINT
    printVec(lnum, "lnum - ");
#endif

    ft.clearResize(ftsize);

    for (int i = n - 1; i >= 0; --i)
    {
#ifdef DPRINTx
        printVec(ft.getft(), "rft - ");
        cout << "insert : " << nums[i] << "\ntotal : " << ft.sum(ftsize - 1) << "\nequal or small : " << ft.sum(nums[i]) << "\n";
#endif
        rnum[i] += ft.sum(ftsize - 1) - ft.sum(nums[i]); // total number of numbers inserted - numbers that are small or equal to current number
        if (ft.sum(nums[i]) - ft.sum(nums[i] - 1) == 0)  // skip adding same number
        {
            ft.add(nums[i], 1);
        }
    }

#ifdef DPRINT
    printVec(rnum, "rnum - ");
#endif

    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret += lnum[i] * rnum[i];
    }

    return ret;
}

class Solution
{
public:
    int countTriplets(vector<int> nums)
    {
        int maxVal = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            maxVal = max(maxVal, nums[i]);
        }

        return solution0ft(maxVal + 1, nums);
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
        int ans = ob.countTriplets(nums);
        cout << ans << "\n";
    }
    return 0;
}
//-----------------------------------------------------------------
