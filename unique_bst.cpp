/*
 * =====================================================================================
 *
 *       Filename:  unique_bst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2013 02:37:40 PM
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
    int numTrees(int n) 
    {
        results.clear();

        // dp(0) == 1
        results.push_back(1);

        for (int i = 1; i <= n; ++i)
        {
            int result = 0;
            for (int j = 1; j <= i / 2; ++j)
                result += 2 * results[j - 1] * results[i - j];

            result += (i % 2) * results[i/2] * results[i/2];
            results.push_back(result);
        }

        return results.back();
    }

private:

    vector<int> results;
};
