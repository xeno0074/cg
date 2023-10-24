// https://leetcode.com/problems/sort-colors/

/*
    two pointers
    left -> all on its left are 0s
    right -> all on its right are 2s

    mid -> to iterate
*/

#include <bits/stdc++.h>

using namespace std;

void printv(const vector<int> &v, const char h[])
{
    cout << h;
    int nMinusOne = v.size() - 1;
    for (int i = 0; i < nMinusOne; ++i)
    {
        cout << v[i] << ", ";
    }

    cout << v[nMinusOne] << "\n";
}

namespace hash_sol
{
    class Solution
    {
    public:
        void sortColors(vector<int> &nums)
        {
            const int n = nums.size();

            int count0 = 0;
            int count1 = 0;
            int count2 = 0;

            for (int i = 0; i < n; ++i)
            {
                switch (nums[i])
                {
                case 0:
                    count0++;
                    break;
                case 1:
                    count1++;
                    break;
                case 2:
                    count2++;
                    break;
                default:
                    break;
                }
            }

            int count01 = count0 + count1;

            for (int i = 0; i < count0; ++i)
            {
                nums[i] = 0;
            }

            for (int i = count0; i < count01; ++i)
            {
                nums[i] = 1;
            }

            for (int i = count01; i < n; ++i)
            {
                nums[i] = 2;
            }
        }
    };
}

namespace two_pointer_sol
{
    void swp(vector<int> &v, int &i, int &j)
    {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    class Solution
    {
    public:
        void sortColors(vector<int> &x)
        {
            int n = x.size();
            int l = 0;
            int r = n - 1;
            int i = 0;

            while (r - l > 2)
            {
                cout << "l : " << l << ", x[l] : " << x[l] << "\n";
                cout << "r : " << r << ", x[r] : " << x[r] << "\n";
                cout << "i : " << i << ", x[i] : " << x[i] << "\n";

                switch (x[i])
                {
                case 0:
                    swp(x, i, l);
                    ++l;
                    break;

                case 2:
                    swp(x, i, r);
                    --r;
                    break;

                default:
                    break;
                }

                ++i;

                printv(x, "x : ");
                cout << "\n";
            }
        }
    };
}

int main()
{
    vector<int> v1{2, 0, 2, 1, 1, 0};
    vector<int> v2{2, 0, 2, 1, 1, 0, 0, 1, 2, 2, 1, 0, 1, 2, 0, 0, 0, 2, 1, 2, 1, 0, 1, 2};

    // hash_sol::Solution s;
    two_pointer_sol::Solution s;

    //------------------------------
    printv(v1, "v1 : ");
    cout << "\n";
    s.sortColors(v1);
    printv(v1, "v1 : ");

    //------------------------------
    printv(v2, "v1 : ");
    cout << "\n";
    s.sortColors(v2);
    printv(v2, "v1 : ");

    return 0;
}