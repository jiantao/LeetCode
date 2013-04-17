/*
 * =====================================================================================
 *
 *       Filename:  min_path_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2013 10:23:07 PM
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
    int minPathSum(vector<vector<int> > &grid) 
    {
        int row = grid.size();
        if (row == 0)
            return 0;

        int col = grid[0].size();
        if (col == 0)
            return 0;

        for (int i = 1; i < col; ++i)
            grid[0][i] += grid[0][i-1];

        for (int i = 1; i < row; ++i)
            grid[i][0] += grid[i-1][0];

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
                grid[i][j] += grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1];
        }

        return grid[row-1][col-1];
    }
};
