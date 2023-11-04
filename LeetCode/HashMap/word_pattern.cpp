// https://leetcode.com/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> c2smap;
        unordered_map<string, char> s2cmap;

        stringstream ss(s);

        string word;
        int i = 0;
        int n = pattern.length();
        while (getline(ss, word, ' '))
        {
            if (i == n)
            {
                return false;
            }

            // cout << "=================================" << endl;
            // cout << pattern[i] << endl;
            // cout << word << endl;

            // cout << c2smap.count(pattern[i]) << endl;
            // cout << s2cmap.count(word) << endl;

            if (c2smap.count(pattern[i]) > 0 || s2cmap.count(word) > 0)
            {
                if (c2smap[pattern[i]] != word || s2cmap[word] != pattern[i])
                {
                    return false;
                }
            }
            else
            {
                c2smap[pattern[i]] = word;
                s2cmap[word] = pattern[i];
            }

            ++i;
        }

        if (i != n)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    string pattern = "abc", s = "abc";

    Solution sol;
    cout << (sol.wordPattern(pattern, s) ? "true" : "false") << endl;
}