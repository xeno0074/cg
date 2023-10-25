// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1176/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int x : nums)
        {
            if (s.count(x) > 0)
            {
                s.erase(x);
            }
            else
            {
                s.insert(x);
            }
        }

        return *s.begin();
    }
};

int main()
{
    vector<int> v1{4, 1, 2, 1, 2};
    Solution s;

    cout << s.singleNumber(v1) << "\n";
}