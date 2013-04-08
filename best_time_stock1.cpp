/*
 * =====================================================================================
 *
 *       Filename:  best_time_stock1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2013 11:18:07 PM
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
            int prevMin = INT_MAX;

            for (unsigned int i = 0; i != prices.size(); ++i)
            {
                if (prevMin > prices[i])
                    prevMin = prices[i];
                else
                {
                    int currMax = prices[i] - prevMin;
                    if (currMax > max)
                        max = currMax;
                }
            }

            return max;
        }
};
