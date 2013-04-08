/*
 * =====================================================================================
 *
 *       Filename:  triangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/2013 07:57:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution_1
{

public: 

    int dfs (const vector<vector<int> > &triangle, int level, int index)
    {
        //the last level
        int size = triangle.size();
        if (level == size - 1)
            return triangle[level][index];

        // go to the left child
        int left = dfs(triangle, level + 1, index);

        // go to the right child
        int right = dfs(triangle, level + 1, index + 1);

        return (left < right ? left + triangle[level][index] : right + triangle[level][index]);
    }

    int minimumTotal(vector<vector<int> > &triangle) 
    {
        int min = INT_MAX;
        if (triangle.size() == 0)
            return min;

        min = dfs(triangle, 0, 0);

        return min;
    }
};
