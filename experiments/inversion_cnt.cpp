#include <bits/stdc++.h>

using namespace std;

class FT
{
    vector<int> t;
    int n;

public:
    FT(int n)
    {
        this->n = n;
        t.resize(n, 0);
    }

    void add(int r, int x)
    {
        for (; r < n; r = r | (r + 1))
        {
            t[r] += x;
        }
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
        {
            ret += t[r];
        }

        return ret;
    }
};

long long
getInversions(long long *arr, int n)
{
    long long count = 0;

    long long maxi = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        maxi = max(maxi, arr[i]);
    }
    ++maxi;

    FT ft(maxi);

    for (int i = n - 1; i >= 0; --i)
    {
        count += ft.sum(arr[i]);
        ft.add(arr[i], 1);
    }

    return count;
}

int main()
{
    long long v[] = {52244275, 123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};
    int n = sizeof(v) / sizeof(v[0]);

    cout << getInversions(v, n) << "\n";
}