// https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>

using namespace std;

bool match(const int &x, const int &y) { return (x ^ y) < 0; }

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;

        for (int x : asteroids)
        {
            bool pushFlag = true;

            while (!stk.empty() && match(stk.top(), x))
            {
                int a = abs(stk.top());
                int b = abs(x);

                if (a == b)
                {
                    stk.pop();
                    pushFlag = false;
                }
                else if (a < b)
                {
                    stk.pop();
                }
                else
                {
                    pushFlag = false;
                    break;
                }
            }

            if (pushFlag)
            {
                stk.push(x);
            }
        }

        vector<int> ans;

        while (!stk.empty())
        {
            ans.emplace_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};

void printv(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    cout << match(1, 3) << endl;
    cout << match(1, -3) << endl;
    cout << match(-1, 3) << endl;
    cout << match(-1, -3) << endl;

    Solution sol;

    vector<int> v1{-2, -1, 1, 2};

    printv(sol.asteroidCollision(v1));
}