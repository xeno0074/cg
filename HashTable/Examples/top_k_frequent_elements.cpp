// https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1133/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> mp; // number -> frequency

bool comparator(int a, int b) { return mp[a] > mp[b]; }

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        mp.clear();
        vector<int> ret;

        for (int num : nums)
        {
            if (mp.count(num) == 0)
            {
                ret.emplace_back(num);
            }
            mp[num]++;
        }

        sort(ret.begin(), ret.end(), comparator);

        return vector<int>(ret.begin(), ret.begin() + k);
    }
};

void printv(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> v{1, 1, 1, 2, 2, 3};

    Solution sol;

    vector<int> res = sol.topKFrequent(v, 2);

    printv(v);
    printv(res);
}