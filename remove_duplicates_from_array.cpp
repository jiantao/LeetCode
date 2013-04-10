/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2013 10:10:23 PM
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
        if (n <= 1)
            return n;

        int last = A[0];
        int svIdx = 1;
        int dupHead = 1;
        int numLeft = n;
        bool inDup = false;

        for (int i = 1; i != n; ++i)
        {
            if (A[i] == last)
            {
                if (!inDup)
                {
                    inDup = true;
                    dupHead = i;
                }
            }
            else
            {
                if (inDup)
                {
                    inDup = false;
                    numLeft -= i - dupHead;
                }

                A[svIdx] = A[i];
                ++svIdx;
            }

            last = A[i];
        }

        if (inDup)
            numLeft -= n - dupHead;

        return numLeft;
    }
};
