/*
 * =====================================================================================
 *
 *       Filename:  pascal_triangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/13/13 15:05:46
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
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int>> result;
        for (int i = 0; i != numRows; ++i)
        {
            vector<int> temp(i + 1, 1);
            if (result.size() >= 2)
            {
                const vector<int>& prev = result.back();
                for (int j = 1; j != i; ++j)
                    temp[j] = prev[j-1] + prev[j];
            }

            result.push_back(temp);
        }

        return result;
    }
};
