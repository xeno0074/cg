// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1117/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool _isIsomorphic(string s, string t)
    {
        unordered_map<char, char> h;

        for (int i = 0; i < s.length(); ++i)
        {
            if (h.count(s[i]) > 0)
            {
                if (h[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                h.insert(make_pair(s[i], t[i]));
            }
        }

        return true;
    }

    bool isIsomorphic(string s, string t)
    {
        cout << s << endl
             << t << endl;
        return _isIsomorphic(s, t) && _isIsomorphic(t, s);
    }
};

int main()
{
    string s1 = "12";
    string s2 = "\u0067\u0068";

    Solution s;
    cout << s.isIsomorphic(s1, s2) << "\n";
}