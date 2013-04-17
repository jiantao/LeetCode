/*
 * =====================================================================================
 *
 *       Filename:  unique_path2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2013 11:41:05 PM
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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
    {
        int row = obstacleGrid.size();
        if (row == 0)
            return 0;

        int col = obstacleGrid[0].size();
        if (col == 0)
            return 0;

        ways.resize(row);
        for (int i = 0; i != row; ++i)
            ways[i].resize(col, 0);

        ways[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        if (ways[0][0] == 0)
            return 0;

        for (int i = 1; i < row; ++i)
            ways[i][0] = obstacleGrid[i][0] == 0 ? ways[i-1][0] : 0;

        for (int i = 1; i < col; ++i)
            ways[0][i] = obstacleGrid[0][i] == 0 ? ways[0][i-1] : 0;

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                if (obstacleGrid[i][j] == 1) 
                    ways[i][j] = 0;
                else
                    ways[i][j] = ways[i-1][j] + ways[i][j-1];
            }
        }

        return ways[row-1][col-1];
    }

private:
    vector<vector<int> > ways;
};
