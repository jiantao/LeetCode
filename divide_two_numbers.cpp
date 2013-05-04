/*
 * =====================================================================================
 *
 *       Filename:  divide_two_numbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 02:55:05 PM
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
    int divide(int dividend, int divisor) 
    {
        bool isNegative = true;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            isNegative = false;


        long long dd = abs((long long) dividend);
        long long dr = abs((long long) divisor);

        unsigned long c = 1;
        while (dr < dd)
        {
            dr = dr << 1;
            c = c << 1;
        }

        int result = 0;
        while (dd >= abs((long long) divisor))
        {
            while (dd >= dr)
            {
                dd -= dr;
                result += c;
            }

            dr = dr >> 1;
            c = c >> 1;
        }

        if (isNegative)
            return -result;

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    cout << solution.divide(-2147483648, 1) << endl;
    return 0;
}
