// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1178/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> countMap1, countMap2;
        unordered_set<int> intersectionSet;
        vector<int> ret;

        for (int x : nums1)
        {
            countMap1[x]++;
        }

        for (int x : nums2)
        {
            if (countMap1.count(x) > 0)
            {
                countMap2[x]++;
            }
        }

        for (auto p : countMap2)
        {
            int c = min(countMap1[p.first], p.second);

            for (int i = 0; i < c; ++i)
            {
                ret.emplace_back(p.first);
            }
        }

        return ret;
    }
};

namespace util
{
    void printv(const vector<int> &v, const char header[] = "")
    {
        cout << header;

        int n = v.size();

        if (n == 0)
        {
            return;
        }

        for (int i = 0; i < n - 1; ++i)
        {
            cout << v[i] << ", ";
        }
        cout << v[n - 1] << "\n";
    }
}

int main()
{
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};
    Solution sol;

    util::printv(sol.intersect(nums1, nums2));
}