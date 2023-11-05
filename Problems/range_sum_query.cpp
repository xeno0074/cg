#include <iostream>
#include <vector>
using namespace std;

namespace g
{
    int N;
    vector<int> A, FT;
}

class NumArray
{
public:
    void printVec(vector<int> v, const char header[])
    {
        cout << header << "\t";
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    void buildFT()
    {
        for (int i = 0; i < g::N; ++i)
        {
            g::FT[i] += g::A[i];
            int p = i | (i + 1);
            if (p < g::N)
            {
                g::FT[p] += g::FT[i];
            }
        }

        printVec(g::FT, "ft-");
    }

    void addFT(int r, int x)
    {
        for (; r < g::N; r = r | (r + 1))
        {
            g::FT[r] += x;
        }
    }

    int sumFT(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
        {
            ret += g::FT[r];
        }

        return ret;
    }

    NumArray(vector<int> &nums)
    {
        g::N = nums.size();
        g::A = nums;
        g::FT.resize(g::N, 0);

        buildFT();
    }

    void update(int index, int val)
    {
        int delta = val - g::A[index];

        addFT(index, delta);
        g::A[index] = val;
    }

    int sumRange(int left, int right)
    {
        return sumFT(right) - sumFT(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> v{-1};

    NumArray na(v);
    cout << na.sumRange(0, 0) << "\n";
    na.update(0, 1);
    cout << na.sumRange(0, 0) << "\n";

    return 0;
}