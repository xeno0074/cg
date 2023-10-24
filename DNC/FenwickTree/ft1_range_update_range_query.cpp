// Instead of storing the array in the fenwick tree, store the differences of array
// elements so prefix sum forms the elements of the given array.
// 1. range update -> adding the delta at range start will propagate the
// sum to all elements in the prefix sums, then we can simply subtract that delta after the range end
// 2. range query -> we can get the range sum by maintaining a secondary fenwick tree to adjust the sum upon update

#include <iostream>
#include <vector>

using namespace std;

class FENWICK_TREE
{
    int n; // array size is N => fenwick tree size is N+1
    vector<int> t;
    vector<int> b;

public:
    FENWICK_TREE(int n)
    {
        this->n = n + 1;
        t.resize(n + 1, 0);
        b.resize(n + 1, 0);
    }

    void build(const vector<int> &a) // build using the diff
    {
        t[1] = a[0];
        if (2 < n)
        {
            t[2] += t[1];
        }

        for (int i = 2; i < n; ++i)
        {
            t[i] += a[i - 1] - a[i - 2];
            int p = i + (i & -i);
            if (p < n)
            {
                t[p] += t[i];
            }
        }
    }

    void add(vector<int> tree, int r, int x)
    {
        for (++r; r < n; r += (r & -r))
        {
            tree[r] += x;
        }
    }

    void range_add(int l, int r, int x)
    {
        add(t, l, x);
        add(t, r + 1, -x);
        add(b, l, x * (l - 1));
        add(b, r + 1, -x * r);
    }

    int sum(vector<int> tree, int r)
    {
        int ret = 0;
        for (++r; r >= 1; r -= (r & -r))
        {
            ret += tree[r];
        }

        return ret;
    }

    int prefix_sum(int r)
    {
        return sum(t, r) * r - sum(b, r);
    }

    int range_sum(int l, int r)
    {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

// TEST ---------------------------------------------------------------------------------------------------------------
void printVec(const vector<int> &v, const char info[])
{
    cout << info;
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<int> getPrefixSum(vector<int> v)
{
    int N = v.size();
    vector<int> sumArr(N);
    sumArr[0] = v[0];
    for (int i = 1; i < N; ++i)
    {
        sumArr[i] = v[i] + sumArr[i - 1];
    }

    return sumArr;
}

void printFtSum(FENWICK_TREE ft, int N, const char info[])
{
    cout << info;
    for (int i = 0; i < N; ++i)
    {
        cout << ft.prefix_sum(i) << " ";
    }
    cout << "\n";
}

int main()
{
    // given array
    vector<int> A{1, 3, -8, 2, -5, 6, 20, 0, 10};
    const int N = A.size();

    FENWICK_TREE ft(N);
    ft.build(A);

    printVec(A, "A-\n");
    printVec(getPrefixSum(A), "sum Array-\n");
    printFtSum(ft, N, "ft.sum Array-\n");

    ft.range_add(2, 4, 50);
    ft.range_add(3, 6, 300);

    printFtSum(ft, N, "ft.sum Array-\n");

    cout << ft.range_sum(2, 6) << endl;

    return 0;
}