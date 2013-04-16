/*
 * =====================================================================================
 *
 *       Filename:  sqrt.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2013 12:16:17 PM
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
    int sqrt(int x) 
    {
        int low = 0;
        int high = x / 2 < std::sqrt(INT_MAX) ? x / 2 + 1 : std::sqrt(INT_MAX);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int val = mid * mid;
            if (val == x)
                return mid;
            else if (val > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return (low + high) / 2;
    }
};

class Solution2
{
public:
    int sqrt(int x)
    {
        if (x == 0)
            return 0;

        double a = x;
        double tol = 1e-5;

        double last = x;
        double val = x;
        do
        {
            last = val;
            val = (val + a / val) / 2;
        }while (abs(val - last) > tol);

        int result = val;
        if (result * result > x)
            --result;

        return result;
    }
};
