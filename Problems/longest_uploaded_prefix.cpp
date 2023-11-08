// https://leetcode.com/problems/longest-uploaded-prefix/

#include <bits/stdc++.h>

using namespace std;

class LUPrefix
{
    vector<int> ft;
    int n;

    inline void init(int n)
    {
        this->n = n + 1;
        ft.resize(this->n, 0);
    }

    inline void add(int r, int x)
    {
        for (; r < n; r += (r & (-r)))
        {
            ft[r] += x;
        }
    }

    inline int sum(int r)
    {
        int ret = 0;

        for (; r > 0; r -= (r & (-r)))
        {
            ret += ft[r];
        }

        return ret;
    }

public:
    LUPrefix(int n) { init(n); }

    void upload(int video) { add(video, 1); }

    int longest()
    {
        if (sum(n - 1) == n - 1)
        {
            return n - 1;
        }

        // binary search to till sum(r) == r
        int l = 1;
        int r = n - 1;
        int ret = 0;
        while (l < r)
        {
            int mid = (r + l) / 2;

            if (sum(mid) != mid)
            {
                r = mid;
            }
            else
            {
                ret = max(ret, mid);
                l = mid + 1;
            }
        }
        return ret;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

int main()
{
    LUPrefix lup(4);

    lup.upload(3);

    cout << lup.longest() << endl;

    lup.upload(1);

    cout << lup.longest() << endl;

    lup.upload(2);

    cout << lup.longest() << endl;

    lup.upload(4);

    cout << lup.longest() << endl;

    return 0;
}