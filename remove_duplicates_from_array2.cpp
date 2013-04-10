/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_array2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2013 10:39:49 PM
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
    int removeDuplicates(int A[], int n) 
    {
        if (n <= 2)
            return n;

        int dupHead = 0;
        int svIdx = 1;
        int dupCount = 0;
        int numLeft = n;
        int last = A[0];

        for (int i = 1; i != n; ++i)
        {
            if (A[i] == last)
            {
                ++dupCount;
                if (dupCount == 1)
                    A[svIdx++] = A[i];
                else if (dupCount == 2)
                    dupHead = i;
            }
            else
            {
                if (dupCount > 1)
                    numLeft -= i - dupHead;

                dupCount = 0;
                A[svIdx++] = A[i];
            }

            last = A[i];
        }

        if (dupCount > 1)
            numLeft -= n - dupHead;

        return numLeft;
    }
};
