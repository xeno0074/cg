// https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1126/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rowSet[9], colSet[9], boxSet[9];

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {

                if (board[i][j] == '.')
                {
                    continue;
                }

                if (rowSet[i].count(board[i][j]) > 0)
                {
                    return false;
                }
                else
                {
                    rowSet[i].insert(board[i][j]);
                }

                if (colSet[j].count(board[i][j]) > 0)
                {
                    return false;
                }
                else
                {
                    colSet[j].insert(board[i][j]);
                }

                int boxId = 3 * (i / 3) + (j / 3);
                if (boxSet[boxId].count(board[i][j]) > 0)
                {
                    return false;
                }
                else
                {
                    boxSet[boxId].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};

class FirstSolution
{
    bool isValidInBox(vector<vector<char>> &board) // check validity in the 3x3 boxes
    {
        for (int boxid = 0; boxid < 9; ++boxid)
        {
            int boxi = boxid / 3;
            int boxj = boxid % 3;

            unordered_set<char> st;

            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    int absi = boxi * 3 + i;
                    int absj = boxj * 3 + j;

                    if (board[absi][absj] == '.')
                    {
                        continue;
                    }

                    if (st.count(board[absi][absj]) > 0)
                    {
                        return false;
                    }
                    else
                    {
                        st.insert(board[absi][absj]);
                    }
                }
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rowSet[9], colSet[9];

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                if (rowSet[i].count(board[i][j]) > 0)
                {
                    return false;
                }
                else
                {
                    rowSet[i].insert(board[i][j]);
                }

                if (colSet[j].count(board[i][j]) > 0)
                {
                    return false;
                }
                else
                {
                    colSet[j].insert(board[i][j]);
                }
            }
        }

        return isValidInBox(board);
    }
};

namespace util
{
    void printvc(const vector<char> &v)
    {
        int n = v.size();
        for (int i = 0; i < n - 1; ++i)
        {
            cout << v[i] << ", ";
        }
        cout << v[n - 1] << "\n";
    }

    void printvvc(const vector<vector<char>> &v)
    {
        int n = v.size();
        for (auto vc : v)
        {
            printvc(vc);
        }
    }
}

int main()
{
    vector<vector<char>> v1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> v2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    //    util::printvvc(v1);
    //    util::printvvc(v2);

    Solution sol;

    int t = clock();
    cout << sol.isValidSudoku(v1) << "\n";
    cout << sol.isValidSudoku(v2) << "\n";
    t = clock() - t;

    cout << "Solution time: " << t << "ms" << endl;

    FirstSolution fsol;

    t = clock();
    cout << fsol.isValidSudoku(v1) << "\n";
    cout << fsol.isValidSudoku(v2) << "\n";
    t = clock() - t;

    cout << "FirstSolution time: " << t << "ms" << endl;

    return 0;
}
