// https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

vector<int> nextSeq(vector<int> seq)
{
    int n = seq.size();
    vector<int> newSeq;

    newSeq.emplace_back(1);

    for (int i = 0; i < n - 1; ++i)
    {
        newSeq.emplace_back(seq[i] + seq[i + 1]);
    }

    newSeq.emplace_back(1);

    return newSeq;
}

vector<vector<int>> generate(int n)
{
    vector<vector<int>> ret{{1}};

    for (int i = 0; i < n - 1; ++i)
    {
        ret.emplace_back(nextSeq(ret[i]));
    }

    return ret;
}

void printP(const vector<vector<int>> &p)
{
    for (vector<int> row_vec : p)
    {
        for (int x : row_vec)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> p = generate(5);

    printP(p);
}