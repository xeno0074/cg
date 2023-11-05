// https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1135/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();

        int startSubstr = 0;
        int maxLen = 0;
        unordered_map<char, int> mp; // char -> last seen index

        for (int j = 0; j < n; ++j)
        {
            if (mp.count(s[j]) > 0)
            {
                startSubstr = max(startSubstr, mp[s[j]] + 1);
            }

            mp[s[j]] = j;
            maxLen = max(maxLen, j - startSubstr + 1);
        }

        return maxLen;
    }
};

int main()
{
    string s = "abba";

    Solution sol;
    cout << s << endl;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}