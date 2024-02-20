class Solution
{
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    inline bool valid(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

    void spreadFire(const vector<vector<int>> &grid, vector<vector<bool>> &fireSeen, queue<vector<int>> &fireQueue,
                    int waitTime)
    {
        int time = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    fireSeen[i][j] = true;
                    fireQueue.push({i, j});
                }
            }
        }

        while (!fireQueue.empty())
        {
            if (time == waitTime)
            {
                return;
            }

            int w = fireQueue.size();

            for (int i = 0; i < w; ++i)
            {
                // int who = q.front()[0];
                int x = fireQueue.front()[0];
                int y = fireQueue.front()[1];
                fireQueue.pop();

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && fireSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        fireSeen[x_][y_] = true;
                        fireQueue.push({x_, y_});
                    }
                }
            }

            time++;
        }
    }

    bool startEscape(const vector<vector<int>> &grid, vector<vector<bool>> &fireSeen, queue<vector<int>> &fireQueue)
    {
        queue<vector<int>> manQueue;
        manQueue.push({0, 0});
        vector<vector<bool>> manSeen(m, vector<bool>(n, false));

        int time = 0;
        int fireReachedFinalAt = -1;

        while (!manQueue.empty())
        {
            int w1 = fireQueue.size();
            int w2 = manQueue.size();

            for (int i = 0; i < w1; ++i)
            {
                int x = fireQueue.front()[0];
                int y = fireQueue.front()[1];
                fireQueue.pop();

                if (x == m - 1 && y == n - 1)
                {
                    fireReachedFinalAt = time;
                }

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && fireSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        fireSeen[x_][y_] = true;
                        fireQueue.push({x_, y_});
                    }
                }
            }

            for (int i = 0; i < w2; ++i)
            {
                int x = manQueue.front()[0];
                int y = manQueue.front()[1];
                manQueue.pop();

                if (x == m - 1 && y == n - 1)
                {
                    if (fireReachedFinalAt == -1 || fireReachedFinalAt == time)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && manSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        if (fireSeen[x_][y_] == false || (x_ == m - 1 && y_ == n - 1))
                        {
                            manSeen[x_][y_] = true;
                            manQueue.push({x_, y_});
                        }
                    }
                }
            }

            time++;
        }

        return false;
    }

    bool check(vector<vector<int>> &grid, int waitTime)
    {
        vector<vector<bool>> fireSeen(m, vector<bool>(n, false));

        queue<vector<int>> fireQueue;

        spreadFire(grid, fireSeen, fireQueue, waitTime);

        return startEscape(grid, fireSeen, fireQueue);
    }

    int maximumMinutes(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        int left = 0;
        int right = m * n;

        if (check(grid, left) == false)
        {
            return -1;
        }

        if (check(grid, right))
        {
            return 1e9;
        }

        while (left < right)
        {
            int mid = (left + right + 1) / 2;

            if (check(grid, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};
class Solution
{
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    inline bool valid(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

    void spreadFire(const vector<vector<int>> &grid, vector<vector<bool>> &fireSeen, queue<vector<int>> &fireQueue,
                    int waitTime)
    {
        int time = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    fireSeen[i][j] = true;
                    fireQueue.push({i, j});
                }
            }
        }

        while (!fireQueue.empty())
        {
            if (time == waitTime)
            {
                return;
            }

            int w = fireQueue.size();

            for (int i = 0; i < w; ++i)
            {
                // int who = q.front()[0];
                int x = fireQueue.front()[0];
                int y = fireQueue.front()[1];
                fireQueue.pop();

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && fireSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        fireSeen[x_][y_] = true;
                        fireQueue.push({x_, y_});
                    }
                }
            }

            time++;
        }
    }

    bool startEscape(const vector<vector<int>> &grid, vector<vector<bool>> &fireSeen, queue<vector<int>> &fireQueue)
    {
        queue<vector<int>> manQueue;
        manQueue.push({0, 0});
        vector<vector<bool>> manSeen(m, vector<bool>(n, false));

        int time = 0;
        int fireReachedFinalAt = -1;

        while (!manQueue.empty())
        {
            int w1 = fireQueue.size();
            int w2 = manQueue.size();

            for (int i = 0; i < w1; ++i)
            {
                int x = fireQueue.front()[0];
                int y = fireQueue.front()[1];
                fireQueue.pop();

                if (x == m - 1 && y == n - 1)
                {
                    fireReachedFinalAt = time;
                }

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && fireSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        fireSeen[x_][y_] = true;
                        fireQueue.push({x_, y_});
                    }
                }
            }

            for (int i = 0; i < w2; ++i)
            {
                int x = manQueue.front()[0];
                int y = manQueue.front()[1];
                manQueue.pop();

                if (x == m - 1 && y == n - 1)
                {
                    if (fireReachedFinalAt == -1 || fireReachedFinalAt == time)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && manSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        if (fireSeen[x_][y_] == false || (x_ == m - 1 && y_ == n - 1))
                        {
                            manSeen[x_][y_] = true;
                            manQueue.push({x_, y_});
                        }
                    }
                }
            }

            time++;
        }

        return false;
    }

    bool check(vector<vector<int>> &grid, int waitTime)
    {
        vector<vector<bool>> fireSeen(m, vector<bool>(n, false));

        queue<vector<int>> fireQueue;

        spreadFire(grid, fireSeen, fireQueue, waitTime);

        return startEscape(grid, fireSeen, fireQueue);
    }

    int maximumMinutes(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        int left = 0;
        int right = m * n;

        if (check(grid, left) == false)
        {
            return -1;
        }

        if (check(grid, right))
        {
            return 1e9;
        }

        while (left < right)
        {
            int mid = (left + right + 1) / 2;

            if (check(grid, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};
class Solution
{
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    inline bool valid(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

    void spreadFire(const vector<vector<int>> &grid, vector<vector<bool>> &fireSeen, queue<vector<int>> &fireQueue,
                    int waitTime)
    {
        int time = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    fireSeen[i][j] = true;
                    fireQueue.push({i, j});
                }
            }
        }

        while (!fireQueue.empty())
        {
            if (time == waitTime)
            {
                return;
            }

            int w = fireQueue.size();

            for (int i = 0; i < w; ++i)
            {
                // int who = q.front()[0];
                int x = fireQueue.front()[0];
                int y = fireQueue.front()[1];
                fireQueue.pop();

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && fireSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        fireSeen[x_][y_] = true;
                        fireQueue.push({x_, y_});
                    }
                }
            }

            time++;
        }
    }

    bool startEscape(const vector<vector<int>> &grid, vector<vector<bool>> &fireSeen, queue<vector<int>> &fireQueue)
    {
        queue<vector<int>> manQueue;
        manQueue.push({0, 0});
        vector<vector<bool>> manSeen(m, vector<bool>(n, false));

        int time = 0;
        int fireReachedFinalAt = -1;

        while (!manQueue.empty())
        {
            int w1 = fireQueue.size();
            int w2 = manQueue.size();

            for (int i = 0; i < w1; ++i)
            {
                int x = fireQueue.front()[0];
                int y = fireQueue.front()[1];
                fireQueue.pop();

                if (x == m - 1 && y == n - 1)
                {
                    fireReachedFinalAt = time;
                }

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && fireSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        fireSeen[x_][y_] = true;
                        fireQueue.push({x_, y_});
                    }
                }
            }

            for (int i = 0; i < w2; ++i)
            {
                int x = manQueue.front()[0];
                int y = manQueue.front()[1];
                manQueue.pop();

                if (x == m - 1 && y == n - 1)
                {
                    if (fireReachedFinalAt == -1 || fireReachedFinalAt == time)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

                for (const vector<int> &dir : dirs)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (valid(x_, y_) && manSeen[x_][y_] == false && grid[x_][y_] != 2)
                    {
                        if (fireSeen[x_][y_] == false || (x_ == m - 1 && y_ == n - 1))
                        {
                            manSeen[x_][y_] = true;
                            manQueue.push({x_, y_});
                        }
                    }
                }
            }

            time++;
        }

        return false;
    }

    bool check(vector<vector<int>> &grid, int waitTime)
    {
        vector<vector<bool>> fireSeen(m, vector<bool>(n, false));

        queue<vector<int>> fireQueue;

        spreadFire(grid, fireSeen, fireQueue, waitTime);

        return startEscape(grid, fireSeen, fireQueue);
    }

    int maximumMinutes(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        int left = 0;
        int right = m * n;

        if (check(grid, left) == false)
        {
            return -1;
        }

        if (check(grid, right))
        {
            return 1e9;
        }

        while (left < right)
        {
            int mid = (left + right + 1) / 2;

            if (check(grid, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};