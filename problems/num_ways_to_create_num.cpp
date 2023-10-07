// https://www.geeksforgeeks.org/introduction-to-dynamic-programming-data-structures-and-algorithm-tutorials/

// s(x) = s(x - 1) + s(x - 3) + s(x - 5)
// s(<0) = 0
// s(0) = 1

#include <iostream>
#include <ctime>

using namespace std;

namespace ref
{
    int solve(int n)
    {
        // base case
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        return solve(n - 1) + solve(n - 3) + solve(n - 5);
    }
}

int s[200];
int s_(int x)
{
    if (x < 0)
    {
        return 0;
    }
    else if (x == 0)
    {
        return 1;
    }
    else
    {
        return s[x];
    }
}

int numWays(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        s[i] = s_(i - 1) + s_(i - 3) + s_(i - 5);
    }

    return s[n];
}

int main()
{
    for (int t = 0; t < 100; ++t)
    {
        int t0 = 0;
        int t1 = 0;
        t0 -= clock();
        int refRes = ref::solve(t);
        t0 += clock();

        t1 -= clock();
        int res = numWays(t);
        t1 += clock();

        if (refRes == res)
        {
            cout << "Pass : ref(" << refRes << "), res(" << res << ")\n";
        }
        else
        {
            cout << "Fail : ref(" << refRes << "), res(" << res << ")\n";
        }

        cout << "ref time: " << t0 << ", actual time: " << t1 << "\n\n";
    }

    return 0;
}