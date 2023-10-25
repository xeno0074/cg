// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1131/

#include <bits/stdc++.h>

using namespace std;

int squaredSumDigits(int x)
{
    int sum = 0;
    while (x)
    {
        int y = x % 10;
        sum += y * y;

        x /= 10;
    }

    return sum;
}

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> s;

        while (1)
        {
            n = squaredSumDigits(n);
            if (s.count(n) > 0)
            {
                return false;
            }
            else if (n == 1)
            {
                return true;
            }
            s.insert(n);
        }
    }
};

int main()
{
    uint64_t x = 19;
    Solution s;
    cout << s.isHappy(x) << "\n";
}