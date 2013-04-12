/*
 * =====================================================================================
 *
 *       Filename:  search_2d_matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/13 11:48:46
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
    bool searchMatrix(vector<vector<int> > &matrix, int target) 
    {
        int row = matrix.size();
        if (row == 0)
            return false;

        int col = matrix[0].size();
        if (col == 0)
            return false;

        for (int i = 0; i != row; ++i)
        {
            if (target >= matrix[i][0] && target <= matrix[i][col-1])
                return binary_search(matrix[i], target, 0, col - 1);
        }

        return false;
    }

private:

    bool binary_search(const vector<int>& array, int target, int low, int high)
    {
        if (low > high)
            return false;

        int mid = (low + high) / 2;

        if (array[mid] == target)
            return true;
        else if (array[mid] > target)
            return binary_search(array, target, low, mid - 1);
        else
            return binary_search(array, target, mid + 1, high);
    }
};
