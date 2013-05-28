/*
 * =====================================================================================
 *
 *       Filename:  rotate_image.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2013 10:11:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "header.hpp"

using namespace std;

class Solution 
{
public:
    void rotate(vector<vector<int> > &matrix) 
    {
        int n = matrix.size();
        int wallSize = matrix.size();

        int sRow = 0;
        int sCol = 0;
        while (wallSize > 1)
        {
            for (int i = 0; i != wallSize - 1; ++i)
            {
                int h = sRow;
                int k = sCol + i;
                int temp = matrix[h][k];
                int temp1 = 0;
                for (int j = 0; j != 4; ++j)
                {
                    int l = h;
                    h = k;
                    k = n - 1 - l;
                    temp1 = matrix[h][k];
                    matrix[h][k] = temp;
                    temp = temp1;
                }

            }

            ++sRow;
            ++sCol;
            wallSize -= 2;
        }
    }
};

class Solution2
{
public:
    void rotate(vector<vector<int> > &matrix) 
    { 
        int row = 0;
        int col = 0;
        int size = matrix.size();
        int end = size - 1;

        while (col < end)
        {
            for (int i = col; i != end; ++i)
            {
                int newRow = row;
                int newCol = i;
                int fromVal = matrix[newRow][newCol];

                for (int j = 0; j != 4; ++j)
                {
                    int temp = newRow;
                    newRow = newCol;
                    newCol = size - 1 - temp;

                    int toVal = matrix[newRow][newCol];
                    matrix[newRow][newCol] = fromVal;
                    fromVal = toVal;
                }
            }

            row += 1;
            col += 1;
            end -= 1;
        }
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix;
    vector<int> temp;

    int n = 5;
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
            temp.push_back(i * n + j + 1);

        matrix.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
            printf("%d\t", matrix[i][j]);

        cout << endl;
    }
    cout << endl;
    cout << endl;

    Solution solution;
    solution.rotate(matrix);

    cout << endl;
    cout << endl;
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
            printf("%d\t", matrix[i][j]);

        cout << endl;
    }
    return 0;
}
