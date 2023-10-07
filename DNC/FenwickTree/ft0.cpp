#include <iostream>
#include <vector>

using namespace std;

struct FENWICK_TREE
{
    vector<int> tree;
    int n;

    FENWICK_TREE(int n) : n(n) { tree.assign(n, 0); }

    int parent(int x)
    {
        return x | (x + 1);
    }

    int child(int x)
    {
        return x & (x + 1);
    }

    void build(const vector<int> &a)
    {
        for (int i = 0; i < n; ++i)
        {
            tree[i] += a[i];

            int p = parent(i);
            if (p < n)
            {
                tree[p] += tree[i];
            }
        }
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = child(r) - 1)
        {
            ret += tree[r];
        }

        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = parent(idx))
        {
            tree[idx] += delta;
        }
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

    printVec(ft.tree, "ft before range update");

    // update 2 to 4 by 5
    ft.add(2, -5);
    ft.add(4 + 1, 5);
    for (int i = 2; i <= 4; ++i)
    {
        A[i] += 5;
    }

    vector<int> newA;
    for (int i = 0; i < N; ++i)
    {
        newA.emplace_back(ft.sum(i, i));
    }
    printVec(newA, "ft each element access");

    printVec(ft.tree, "ft after range update");
}
