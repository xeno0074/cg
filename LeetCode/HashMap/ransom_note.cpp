// https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> cmap;

        for (char c : magazine)
        {
            cmap[c]++;
        }

        for (char c : ransomNote)
        {
            if (cmap[c] > 0)
            {
                // available so use up and delete one char in the count map
                cmap[c]--;
            }
            else
            {
                // none available
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string ransomNote = "aa", magazine = "ab";
    Solution sol;
    cout << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

    return 0;
}