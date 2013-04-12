/*
 * =====================================================================================
 *
 *       Filename:  set_matrix_zeroes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/13 16:58:07
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
    void setZeroes(vector<vector<int> > &matrix) 
    {
        int row = matrix.size();
        int col = 0;
        if (row == 0)
            return;
        else
            col = matrix[0].size();

        if (col == 0)
            return;

        int hRow = -1;
        int hCol = -1;

        for (int i = 0; i != row; ++i)
        {
            for (int j = 0; j != col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    hRow = i;
                    hCol = j;
                    break;
                }
            }

            if (hRow != -1)
                break;
        }

        if (hRow == -1)
            return;

        for (int i = 0; i != col; ++i)
        {
            if (matrix[hRow][i] != 0)
                matrix[hRow][i] = 1;
        }

        for (int i = 0; i != row; ++i)
        {
            if (matrix[i][hCol] != 0)
                matrix[i][hCol] = 1;
        }

        for (int i = 0; i != row; ++i)
        {
            if (i == hRow)
                continue;
            for (int j = 0; j != col; ++j)
            {
                if (j == hCol)
                    continue;

                if (matrix[i][j] == 0)
                {
                    matrix[i][hCol] = 0;
                    matrix[hRow][j] = 0;
                }
            }
        }

        for (int i = 0; i != row; ++i)
        {
            if (i == hRow)
                continue;
            for (int j = 0; j != col; ++j)
            {
                if (j == hCol)
                    continue;
                if (matrix[hRow][j] == 0 || matrix[i][hCol] == 0)
                    matrix[i][j] = 0;
            }
        }

        for (int i = 0; i != col; ++i)
            matrix[hRow][i] = 0;

        for (int i = 0; i != row; ++i)
            matrix[i][hCol] = 0;
    }
};
