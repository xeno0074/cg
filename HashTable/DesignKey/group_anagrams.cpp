// https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1124/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    inline string getKey(string str)
    {
        sort(str.begin(), str.end());
        return str;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> ret;
        int k = 0;
        unordered_map<string, int> mp; // key(string) -> index on the ret vector

        for (string str : strs)
        {
            string key = getKey(str);

            if (mp.count(key) > 0) // key exists so only append at the index
            {
                ret[mp[key]].emplace_back(str);
            }
            else // create a new entry with index in the ret vector
            {
                vector<string> tmp;
                tmp.push_back(str);
                ret.emplace_back(tmp);
                mp[key] = k;
                k++;
            }
        }

        return ret;
    }
};

namespace util
{
    void printvs(const vector<string> &v)
    {
        int n = v.size();
        for (int i = 0; i < n - 1; ++i)
        {
            cout << v[i] << ", ";
        }
        cout << v[n - 1] << "\n";
    }

    void printvvs(const vector<vector<string>> &v)
    {
        int n = v.size();
        for (auto vs : v)
        {
            printvs(vs);
        }
    }
}

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;

    vector<vector<string>> res = sol.groupAnagrams(strs);

    util::printvvs(res);
}