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

        for (int i = 0; i != n; ++i)
        {
            currSum += A[i];
            if (currSum > max)
                max = currSum;

            if (currSum < 0)
                currSum = 0;
        }

        return max;
    }
};
