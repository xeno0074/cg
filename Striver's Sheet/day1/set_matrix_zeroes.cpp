// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    int row_zero_bmp[num_rows]{0};
    int col_zero_bmp[num_cols]{0};

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                row_zero_bmp[i] = 1;
                col_zero_bmp[j] = 1;
            }
        }
    }

    for (int i = 0; i < num_rows; ++i)
    {
        if (row_zero_bmp[i])
        {
            for (int j = 0; j < num_cols; ++j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < num_cols; ++j)
    {
        if (col_zero_bmp[j])
        {
            for (int i = 0; i < num_rows; ++i)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMat(const vector<vector<int>> &matrix)
{
    for (vector<int> row_vec : matrix)
    {
        for (int x : row_vec)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> matrix{{0, 1, 2, 0},
                               {3, 4, 5, 2},
                               {1, 3, 1, 5}};

    setZeroes(matrix);

    printMat(matrix);
}