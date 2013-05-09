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
        int area = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end)
        {
            int h = height[start] < height[end] ? height[start] : height[end];
            area = max(area, h * (end - start));
            if (h == height[start])
                ++start;
            else 
                --end;
        }

        return area;
    }
};
