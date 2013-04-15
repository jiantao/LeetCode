/*
 * =====================================================================================
 *
 *       Filename:  sort_colors.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2013 12:12:08 AM
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

class Solution1
{
public:
    void sortColors(int A[], int n) 
    {
        int counts[] = {0, 0, 0};

        for (int i = 0; i != n; ++i)
            ++counts[A[i]];

        int j = 0;
        for (int i = 0; i != 3; ++i)
        {
            int end = j + counts[i];
            for (; j != end; ++j)
                A[j] = i;
        }
    }
};

class Solution2
{
public:
    void sortColors(int A[], int n) 
    {
        int h0 = 0;
        int h2 = n - 1;
        int i = 0;

        while (i < h2 + 1)
        {
            if (A[i] == 0)
            {
                swap(A[h0], A[i]);
                ++h0;
                ++i;
            }
            else if (A[i] == 2)
            {
                swap(A[h2], A[i]);
                --h2;
            }
            else
                ++i;
        }
    }
};
