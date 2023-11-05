// https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1136/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set<char> jewelsSet;

        for (char c : jewels)
        {
            jewelsSet.insert(c);
        }

        int count = 0;

        for (char stone : stones)
        {
            if (jewelsSet.count(stone) > 0)
            {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    string jewels = "aA";
    string stones = "aAAbbbb";

    Solution sol;

    cout << sol.numJewelsInStones(jewels, stones) << endl;

    return 0;
}