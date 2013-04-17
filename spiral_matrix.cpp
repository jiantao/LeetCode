/*
 * =====================================================================================
 *
 *       Filename:  spiral_matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/13 11:28:35
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
    Solution()
    {
        nextSteps.resize(4);
        rowDirect.resize(4);
        colDirect.resize(4);

        rowDirect[0] = 0;
        rowDirect[1] = 1;
        rowDirect[2] = 0;
        rowDirect[3] = -1;

        colDirect[0] = 1;
        colDirect[1] = 0;
        colDirect[2] = -1;
        colDirect[3] = 0;
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        result.clear();
        int row = matrix.size();
        if (row == 0)
            return result;

        int col = matrix[0].size();
        if (col == 0)
            return result;

        setSteps(row, col);
        int h = 0;
        int k = -1;

        int steps;
        while (true)
        {
            for (int i = 0; i != 4; ++i)
            {
                steps = nextSteps[i];
                if (steps <= 0)
                    break;

                for (int j = 0; j != steps; ++j)
                {
                    h += rowDirect[i];
                    k += colDirect[i];

                    result.push_back(matrix[h][k]);
                }

            }

            if (steps > 0)
                setSteps(nextSteps[3], nextSteps[0] - 2);
            else
                break;
        }

        return result;
    }

private:
    void setSteps(int row, int col)
    {
        nextSteps[0] = col;
        nextSteps[1] = row - 1;
        nextSteps[2] = col - 1;
        nextSteps[3] = row - 2;
    }

private:
    vector<int> result;
    vector<int> nextSteps;
    vector<int> rowDirect;
    vector<int> colDirect;
};
