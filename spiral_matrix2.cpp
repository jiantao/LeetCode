/*
 * =====================================================================================
 *
 *       Filename:  spiral_matrix2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/13 13:37:42
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
    vector<vector<int> > generateMatrix(int n) 
    {
        rowDirect[0] = 0;
        rowDirect[1] = 1;
        rowDirect[2] = 0;
        rowDirect[3] = -1;

        colDirect[0] = 1;
        colDirect[1] = 0;
        colDirect[2] = -1;
        colDirect[3] = 0;

        matrix.resize(n);
        for (int i = 0; i != n; ++i)
            matrix[i].resize(n, 0);

        int total = n * n;

        int h = 0;
        int k = 0;
        int direct = 0;

        for (int i = 0; i < total; ++i)
        {
            if (h < 0 || h >= n || k < 0 || k >= n || matrix[h][k] != 0)
            {
                h -= rowDirect[direct];
                k -= colDirect[direct];
                direct = (direct + 1) % 4;

                h += rowDirect[direct];
                k += colDirect[direct];
            }

            matrix[h][k] = i + 1;

            h += rowDirect[direct];
            k += colDirect[direct];
        }

        return matrix;
    }

private:
    vector<vector<int> > matrix;
    int rowDirect[4];
    int colDirect[4];
};

int main(int argc, char *argv[])
{
    Solution solution;
    int n = 5;
    vector<vector<int> > matrix = solution.generateMatrix(n);
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
            cout << matrix[i][j] << "\t";

        cout << endl;
    }

    return 0;
}
