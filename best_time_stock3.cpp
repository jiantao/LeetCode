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

class SolutionDup
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int maxProfit = 0;
        int size = prices.size();
        if (size < 2)
            return maxProfit;

        vector<int> firstBest(size, 0);
        int min = prices[0];
        int currMax = 0;

        for (int i = 1; i < size; ++i)
        {
            if (prices[i] > min)
            {
                int diff = prices[i] - min;
                if (diff > currMax)
                    currMax = diff;
            }
            else
                min = prices[i];

            firstBest[i] = currMax;
        }

        int max = prices[size-1];
        currMax = 0;

        for (int i = size - 1; i >= 0; --i)
        {
            if (prices[i] < max)
            {
                int diff = max - prices[i];
                if (diff > currMax)
                    currMax = diff;
            }
            else
                max = prices[i];

            if (currMax + firstBest[i] > maxProfit)
                maxProfit = currMax + firstBest[i];
        }

        return maxProfit;
    }
};
