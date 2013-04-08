/*
 * =====================================================================================
 *
 *       Filename:  best_time_stock3.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2013 12:09:34 AM
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
            int size = prices.size();
            if (size < 2)
                return 0;

            int prevMin = prices[0];
            int max = 0;
            vector<int> prevMax(size, 0);

            for (int i = 1; i != size; ++i)
            {
                if (prevMin > prices[i])
                    prevMin = prices[i];
                else
                {
                    int currMax = prices[i] - prevMin;
                    if (currMax > max)
                        max = currMax;
                }

                prevMax[i] = max;
            }

            int maxProfit = prevMax[size - 1];
            int afterMax = prices[size - 1];
            max = 0;
            for (int i = size - 2; i >= 0; --i)
            {
                if (afterMax < prices[i])
                    afterMax = prices[i];
                else
                {
                    int currMax = afterMax - prices[i];
                    if (currMax > max)
                        max = currMax;
                }

                if (max + prevMax[i] > maxProfit)
                    maxProfit = max + prevMax[i];
            }

            return maxProfit;
        }
};
