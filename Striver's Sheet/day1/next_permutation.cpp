// https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int> &nums, int start = 0)
{
    int n = nums.size();
    int loop_limit = (n - start) / 2;

    for (int i = 0; i < loop_limit; ++i)
    {
        swap(nums[start + i], nums[n - i - 1]);
    }
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0 || n == 1)
    {
        return;
    }

    int bp = n - 2;
    int rep; // bp element to be replaced with

    for (; bp >= 0; --bp)
    {
        if (nums[bp] < nums[bp + 1])
        {
            break;
        }
    }

    if (bp == -1)
    {
        // bp element not found
        bp = 0;
    }
    else
    {
        // find element just greater than bp element and swap
        rep = bp + 1;
        while (rep < n)
        {
            if (nums[rep] < nums[bp])
            {
                break;
            }
            rep++;
        }
        rep--;
        swap(nums[bp], nums[rep]);
        ++bp;
    }

    cout << "bp=" << bp << "\n";
    cout << "rep=" << rep << "\n";

    sort(nums.begin() + bp, nums.end());
}

void printv(const vector<int> &v, const char header[] = "", const char separator[] = ", ")
{
    cout << header;

    int n = v.size();

    for (int i = 0; i < n - 1; ++i)
    {
        cout << v[i] << separator;
    }
    cout << v[n - 1] << "\n";
}

int main()
{
    vector<int> v1{8, 3, 6, 9, 7, 4, 2};
    vector<int> v2{1, 2, 3};
    vector<int> v3{3, 2, 1};
    vector<int> v4{1, 1, 5};
    vector<int> v5{1, 2};
    vector<int> v6{1, 5, 1};

    printv(v1);
    nextPermutation(v1);
    printv(v1);

    cout << "-------------------------\n";
    printv(v2);
    nextPermutation(v2);
    printv(v2);

    cout << "-------------------------\n";
    printv(v3);
    nextPermutation(v3);
    printv(v3);

    cout << "-------------------------\n";
    printv(v4);
    nextPermutation(v4);
    printv(v4);

    cout << "-------------------------\n";
    printv(v5);
    nextPermutation(v5);
    printv(v5);

    cout << "-------------------------\n";
    printv(v6);
    nextPermutation(v6);
    printv(v6);
}