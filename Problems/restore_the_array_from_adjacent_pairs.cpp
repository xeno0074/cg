// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/?envType=daily-question&envId=2023-11-10

#include <bits/stdc++.h>

using namespace std;

void printv(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

class Solution
{
    int findFirstUnique(const vector<vector<int>> &v)
    {
        int ret;

        int nr = v.size();
        int nc = v[0].size();
        unordered_map<int, int> cntMp;

        for (int i = 0; i < nr; ++i)
        {
            for (int j = 0; j < nc; ++j)
            {
                cntMp[v[i][j]]++;
            }
        }

        for (int i = 0; i < nr; ++i)
        {
            for (int j = 0; j < nc; ++j)
            {
                if (cntMp[v[i][j] == 1])
                {
                    ret = v[i][j];
                    break;
                }
            }
        }

        return ret;
    }

public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int n = adjacentPairs.size() + 1;
        vector<int> ret(n);

        unordered_map<int, int> adjMap;

        for (vector<int> p : adjacentPairs)
        {
            adjMap[p[0]] = p[1];
            adjMap[p[1]] = p[0];
        }

        string s = "simanta";
        swap(s[0], s[6]);
        cout << s << endl;

        // find first unique number in adjacentPairs
        ret[0] = findFirstUnique(adjacentPairs);

        for (int i = 1; i < n; ++i)
        {
            cout << ret[i - 1] << endl;
        }

        return ret;
    }
};

int main()
{
    vector<vector<int>> adjPairs{{2, 1}, {3, 4}, {3, 2}};
    Solution sol;
    vector<int> res = sol.restoreArray(adjPairs);
    printv(res);
}