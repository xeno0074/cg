// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1120/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> countMap;

        for (int i = 0; i < s.length(); ++i)
        {
            if (countMap.count(s[i]) > 0)
            {
                ++countMap[s[i]];
            }
            else
            {
                countMap.insert(make_pair(s[i], 1));
            }
        }

        for (int i = 0; i < s.length(); ++i)
        {
            if (countMap[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    string str = "loveleetcode";
    Solution sol;

    cout << sol.firstUniqChar(str) << "\n";
}