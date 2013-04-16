/*
 * =====================================================================================
 *
 *       Filename:  climbing_stairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2013 10:51:50 AM
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
    int climbStairs(int n) 
    {
        ways.clear();
        ways.resize(n + 1);
        ways[0] = 1;
        ways[1] = 1;

        for (int i = 2; i <= n; ++i)
            ways[i] = ways[i-1] + ways[i-2];

        return ways[n];
    }

private:
    vector<int> ways;
};
