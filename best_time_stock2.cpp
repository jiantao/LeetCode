/*
 * =====================================================================================
 *
 *       Filename:  best_time_stock2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2013 11:49:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <vector>
#include <limits.h>

using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int> &prices) 
        {
            int max = 0;
            int prev = INT_MAX;
            for (unsigned int i = 0; i != prices.size(); ++i)
            {
                if (prev < prices[i])
                    max += prices[i] - prev;

                prev = prices[i];
            }

            return max;
        }
};
