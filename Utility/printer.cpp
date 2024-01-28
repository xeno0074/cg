#include <bits/stdc++.h>

// #define MONGKI
// #define PRINT_FUNCS

#ifndef PRINT_FUNCS
#define e_ , endLine()
#define s_ , spaceLine()

void endLine() { cout << '\n'; }
void spaceLine() { cout << " "; }

// print single
template <typename T> void print(const T &data) { cout << data; }

// multiple style of single -> prints(val1, val2, val3, ...., valn);
void prints() {}

template <typename T, typename... Args> void prints(const T &first, const Args &...rest)
{
    cout << first;
    if (sizeof...(rest) > 0)
        cout << ", ";

    prints(rest...);
}

template <typename T1, typename T2> void print(const pair<T1, T2> &data)
{
    auto &[a, b] = data;
    cout << "(" << a << ", " << b << ")";
}

template <typename T1, typename T2, typename T3> void print(const tuple<T1, T2, T3> &data)
{
    auto &[a, b, c] = data;
    cout << "(" << a << ", " << b << ", " << c << ")";
}

// print vector
template <typename T> void print(const vector<T> &data, int in_row = 0)
{

    int n = data.size();

    if (!in_row)
        cout << "[";
    for (int i = 0; i < n; i++)
    {
        print(data[i]);

        if (in_row)
        {
            cout << '\n';
        }
        else if (i != n - 1)
        {
            cout << ", ";
        }
    }
    if (!in_row)
        cout << "]";
}

template <typename T> void print(const vector<vector<T>> &data, int in_row = 0)
{
    int n = data.size();

    if (!in_row)
        cout << "[";
    for (int i = 0; i < n; i++)
    {
        print(data[i], 0);

        if (in_row)
        {
            cout << '\n';
        }
        else if (i != n - 1)
        {
            cout << ", ";
        }
    }
    if (!in_row)
        cout << "]";
}

template <typename T1, typename T2> void print(const vector<pair<T1, T2>> &data, int in_row = 0)
{
    int n = data.size();

    if (!in_row)
        cout << "[";
    for (int i = 0; i < n; i++)
    {
        print(data[i]);

        if (in_row)
        {
            cout << '\n';
        }
        else if (i != n - 1)
        {
            cout << ", ";
        }
    }
    if (!in_row)
        cout << "]";
}

template <typename T1, typename T2> void print(const vector<vector<pair<T1, T2>>> &data, int in_row = 0)
{
    int n = data.size();

    if (!in_row)
        cout << "[";
    for (int i = 0; i < n; i++)
    {
        print(data[i]);

        if (in_row)
        {
            cout << '\n';
        }
        else if (i != n - 1)
        {
            cout << ", ";
        }
    }
    if (!in_row)
        cout << "]";
}

// print set
template <typename T> void print(const set<T> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        print(*it);

        if (in_row)
        {
            cout << "\n";
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

template <typename T1, typename T2> void print(const set<pair<T1, T2>> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        print(*it);

        if (in_row)
        {
            cout << "\n";
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

// print map
template <typename K, typename V> void print(const map<K, V> &data, int in_row = 0)
{
    if (data.empty())
        return;
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        auto &[a, b] = *it;

        print(a);
        cout << ": ";
        print(b);

        if (in_row)
        {
            cout << '\n';
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

template <typename K, typename V1, typename V2> void print(const map<K, pair<V1, V2>> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        auto &[a, b] = *it;

        print(a);
        cout << ": ";
        print(b);

        if (in_row)
        {
            cout << '\n';
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

template <typename K, typename V> void print(const map<K, vector<V>> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        auto &[a, b] = *it;

        print(a);
        cout << ": ";
        print(b, 0);

        if (in_row)
        {
            cout << '\n';
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

template <typename K, typename V> void print(const map<K, set<V>> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        auto &[a, b] = *it;

        print(a);
        cout << ": ";
        print(b, 0);

        if (in_row)
        {
            cout << '\n';
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

template <typename K1, typename K2, typename V> void print(const map<pair<K1, K2>, V> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        auto &[a, b] = *it;

        print(a);
        cout << ": ";
        print(b);

        if (in_row)
        {
            cout << '\n';
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}

template <typename K1, typename K2, typename K3, typename V>
void print(const map<tuple<K1, K2, K3>, V> &data, int in_row = 0)
{
    auto last = prev(data.end());
    auto it = data.begin();

    if (!in_row)
        cout << "{";
    while (it != data.end())
    {
        auto &[a, b] = *it;

        print(a);
        cout << ": ";
        print(b);

        if (in_row)
        {
            cout << '\n';
        }
        else if (it != last)
        {
            cout << ", ";
        }

        it++;
    }
    if (!in_row)
        cout << "}";
}
#endif

#ifndef MONGKI
using namespace std;
#define M_PI 3.14159265358979323846
#define umap unordered_map
#define uset unordered_set
#define prioq(T) priority_queue<T, vector<T>, T>
#define great(T) T, vector<T>, greater<T>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define pb push_back
using pivi = pair<int, vector<int>>;

template <size_t Size> string getBin(int value)
{
    bitset<Size> binaryRepresentation(value);
    string binaryString = binaryRepresentation.to_string();
    return binaryString;
}

void OIHack()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename T> struct Modulo
{
    static const int MOD = 1e9 + 7;
    T add(T a, T b, int mod = MOD) { return (a + b + mod) % mod; }
    T sub(T a, T b, int mod = MOD) { return (a - b + mod) % mod; }
    T mul(T a, T b, int mod = MOD) { return ((a % mod) * (b % mod)) % mod; }
    T div(T a, T b, int mod = MOD) { return mul(a, pwr(b, mod - 2)); }
    T pwr(T base, T expo, int mod = MOD)
    {
        T result = 1;
        T baseLL = base;
        while (expo > 0)
        {
            if (expo % 2 == 1)
                result = mul(result, baseLL, mod);

            baseLL = mul(baseLL, baseLL, mod);
            expo /= 2;
        }
        return result;
    }
};

// down, right, up, left, upleft, downright, upright, downleft
const int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int dx[8] = {0, 1, 0, -1, -1, 1, 1, -1};
Modulo<int64_t> mod;
#endif

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int R = maze.size(), C = maze[0].size();

        vector<vector<int>> vis(R, vector<int>(C, 0));
        int sy = entrance[0], sx = entrance[1];
        vis[sy][sx] = 1;

        queue<pii> que;
        for (int i = 0; i < 4; i++)
        {
            int y = sy + dy[i], x = sx + dx[i];
            if (y < 0 || x < 0 || y >= R || x >= C)
                continue;
            if (maze[y][x] == '+')
                continue;
            vis[y][x] = 1, que.push({y, x});
        }

        for (int step = 1; !que.empty(); step++)
        {
            int n = que.size();
            while (n--)
            {
                auto [y, x] = que.front();
                que.pop();
                if (y == R - 1 || y == 0 || x == C - 1 || x == 0)
                    return step;

                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                        continue;
                    if (vis[ny][nx] || maze[ny][nx] == '+')
                        continue;

                    vis[ny][nx] = 1, que.push({ny, nx});
                }
            }
        }

        return -1;
    }
};

#define MAIN_DISABLE
#ifndef MAIN_DISABLE
int main() { return EXIT_SUCCESS; }
#endif