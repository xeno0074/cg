#include <iostream>
#include <vector>

using namespace std;

class FENWICK_TREE
{
public:
    int n; // array size is N => fenwick tree size is N+1
    vector<int> t;

    FENWICK_TREE(int n)
    {
        this->n = n + 1;
        t.resize(n + 1, 0);
    }

    void build(const vector<int> &a)
    {
        for (int i = 1; i < n; ++i)
        {
            t[i] += a[i - 1];
            int p = i + (i & -i);
            if (p < n)
            {
                t[p] += t[i];
            }
        }
    }

    void add(int r, int x)
    {
        for (++r; r < n; r += (r & -r))
        {
            t[r] += x;
        }
    }

    int sum(int r)
    {
        int ret = 0;
        for (++r; r >= 1; r -= (r & -r))
        {
            ret += t[r];
        }

        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

void printVec(const vector<int> &v, const char info[])
{
    cout << info << "\n";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> A{1, 3, -8, 2, -5, 6, 20, 0, 10};
    const int N = A.size();

    FENWICK_TREE ft(N);
    ft.build(A);

    // // update 2 to 4 by 5
    // ft.add(2, -5);
    // ft.add(4 + 1, 5);
    // for (int i = 2; i <= 4; ++i)
    // {
    //     A[i] += 5;
    // }

    // vector<int> newA;
    // for (int i = 0; i < N; ++i)
    // {
    //     newA.emplace_back(ft.sum(i, i));
    // }
    // printVec(newA, "ft each element access");

    // printVec(ft.t, "ft after range update");

    vector<int> sumArr(N);
    sumArr[0] = A[0];
    for (int i = 1; i < N; ++i)
    {
        sumArr[i] = A[i] + sumArr[i - 1];
    }

    printVec(A, "A-");
    printVec(sumArr, "sumArr-");

    cout << "ft.sum list-\n";
    for (int i = 0; i < N; ++i)
    {
        cout << ft.sum(i) << " ";
    }
    cout << "\n";

    for (int i = 0; i < N; ++i)
    {
        if (ft.sum(i) != sumArr[i])
        {
            cout << "Failure\n";
            break;
        }
    }

    cout << "ft.sum list-\n";
    for (int i = 0; i < N; ++i)
    {
        cout << ft.sum(i) << " ";
    }
    cout << "\n";

    printVec(ft.t, "ft.t-");
}