/*
 * =====================================================================================
 *
 *       Filename:  merge_sorted_arrays.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2013 10:57:03 PM
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
    void merge(int A[], int m, int B[], int n) 
    {
        int tail = m + n - 1;
        int aEnd = m - 1;
        int bEnd = n - 1;

        while (aEnd >= 0 && bEnd >= 0)
        {
            if (A[aEnd] >= B[bEnd])
                A[tail] = A[aEnd--];
            else
                A[tail] = B[bEnd--];

            --tail;
        }

        if (bEnd < 0)
            return;

        if (aEnd < 0)
        {
            while (bEnd >= 0)
                A[tail--] = B[bEnd--];
        }
    }
};
