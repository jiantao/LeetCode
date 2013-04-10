/*
 * =====================================================================================
 *
 *       Filename:  combination.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2013 03:18:40 PM
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
    vector<vector<int> > combine(int n, int k) 
    {
        results.clear();
        tempResult.clear();
        total = n;
        dfs(1, k);

        return results;
    }

private:
    void dfs(int num, int numLeft)
    {
        if (numLeft == 0)
        {
            results.push_back(tempResult);
            return;
        }

        int remains = total - num;
        int numPush = 0;
        for (int i = 0; i <= 1; ++i)
        {
            if (i > 0)
            {
                tempResult.push_back(num);
                ++numPush;
            }

            if (remains + i < numLeft)
                continue;

            dfs(num + 1, numLeft - i);
        }

        for (int i = 0; i != numPush; ++i)
            tempResult.pop_back();
    }

private:

    int total;
    vector<int> tempResult;
    vector<vector<int> > results;
};
