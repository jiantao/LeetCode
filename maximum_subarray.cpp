/*
 * =====================================================================================
 *
 *       Filename:  maximum_subarray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2013 05:06:38 PM
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
    int maxSubArray(int A[], int n) 
    {
        int max = INT_MIN;

        int currSum = 0;
        int maxSum = 0;

        for (int i = 0; i != n; ++i)
        {
            if (max < A[i])
                max = A[i];
        }

        if (max <= 0)
            return max;

        for (int i = 0 ; i != n; ++i)
        {
            currSum += A[i];
            if (currSum > 0)
            {
                if (currSum > maxSum)
                    maxSum = currSum;
            }
            else
                currSum = 0;
        }

        return maxSum;
    }
};
