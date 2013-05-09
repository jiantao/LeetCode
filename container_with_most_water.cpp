/*
 * =====================================================================================
 *
 *       Filename:  container_with_most_water.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2013 11:27:35 PM
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
    int maxArea(vector<int> &height) 
    {
        stack.clear();
        int maxArea = 0;
        int size = height.size();

        stack.push_back(0);
        for (int i = 1 ; i < size; ++i)
        {
            int topIdx = stack.back();
            if (height[i] > height[topIdx])
        }
    }

private:
    vector<int> stack;
};
