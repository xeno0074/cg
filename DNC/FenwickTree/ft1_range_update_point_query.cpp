// Instead of storing the array in the fenwick tree, store the differences of array
// elements so prefix sum forms the elements of the given array.
// 1. point query -> when we need to get an random element, we can simply take the prefix sum till that index
// 2. range update -> adding the delta at range start will propagate the
// sum to all elements in the prefix sums, then we can simply subtract that delta after the range end

#include <iostream>
#include <vector>

using namespace std;

class FENWICK_TREE
{
    int n; // array size is N => fenwick tree size is N+1
    vector<int> t;

public:
    FENWICK_TREE(int n)
    {
        this->n = n + 1;
        t.resize(n + 1, 0);
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

    void add(int r, int x)
    {
        for (++r; r < n; r += (r & -r))
        {
            t[r] += x;
        }
    }

    void range_add(int l, int r, int x)
    {
        add(l, x);
        add(r + 1, -x);
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

    int point_query(int r)
    {
        return sum(r);
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
        cout << ft.sum(i) << " ";
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

    cout << ft.point_query(6) << endl;

    return 0;
}