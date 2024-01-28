// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> cntMap;

template <class T> class Comparator
{
public:
    bool operator()(T a, T b)
    {
        // cout << a << "-cnt-" << cntMap[a] << endl;
        // cout << b << "-cnt-" << cntMap[b] << endl;
        return true;
        // return cntMap[a] >= cntMap[b];
    }
};

class Solution
{
public:
    string frequencySort(string s)
    {
        cntMap.clear();

        for (char c : s)
        {
            cntMap[c]++;
        }

        sort(s.begin(), s.end(), Comparator<char>());

        return s;
    }
};

int main()
{
    string s = "2a554442f544asfasssffffasss";
    Solution sol;
    cout << sol.frequencySort(s) << endl;
}


// 