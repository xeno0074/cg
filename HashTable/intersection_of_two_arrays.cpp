// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1105/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s, sx;
        vector<int> v;

        for (int x : nums1)
        {
            s.insert(x);
        }

        for (int x : nums2)
        {
            if (s.count(x) > 0)
            {
                sx.insert(x);
            }
        }

        for (int x : sx)
        {
            v.emplace_back(x);
        }

        return v;
    }
};

void printv(const vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i <= n - 2; ++i)
    {
        cout << v[i] << ", ";
    }
    cout << v[n - 1] << "\n";
}

int main()
{
    vector<int> v1{4, 9, 5};
    vector<int> v2{9, 4, 9, 8, 4};

    Solution s;
    printv(s.intersection(v1, v2));
}