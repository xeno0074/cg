// https://leetcode.com/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> cmap;

        for (char c : s)
        {
            cmap[c]++;
        }

        for (char c : t)
        {
            if (cmap[c] > 0)
            {
                cmap[c]--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main() {}