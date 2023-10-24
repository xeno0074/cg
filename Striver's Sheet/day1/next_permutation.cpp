// https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>

using namespace std;

void swap(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

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

    if (n == 1)
    {
        return;
    }

    int bp = n - 2;

    for (; bp >= 0; --bp)
    {
        if (nums[bp] < nums[bp + 1])
        {
            break;
        }
        if (bp == 0)
        {
            reverse(nums);
            return;
        }
    }

    int just_gt_bp = bp + 1;

    for (; just_gt_bp < n; ++just_gt_bp)
    {
        if (nums[bp] > nums[just_gt_bp])
        {
            break;
        }
    }
    --just_gt_bp;

    swap(nums[bp], nums[just_gt_bp]);

    reverse(nums, bp + 1);
}

void printV(const vector<int> &v, const char header[] = "", const char separator[] = ", ")
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
    vector<int> v2{3, 2, 1};
    vector<int> v3{1, 2};
    vector<int> v4{1, 5, 1};

    nextPermutation(v1);
    printV(v1);

    nextPermutation(v2);
    printV(v2);

    nextPermutation(v3);
    printV(v3);

    nextPermutation(v4);
    printV(v4);
}