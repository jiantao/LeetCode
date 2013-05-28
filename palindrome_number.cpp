/*
 * =====================================================================================
 *
 *       Filename:  palindrome_number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2013 08:17:16 PM
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
    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;

        int p = log10(x);
        while (x > 9)
        {
            int base = pow(10, p);
            int high = x / base;
            int low = x % 10;

            if (high != low)
                return false;

            x -= high * base;
            x = x / 10;
            p -= 2;
        }

        return true;
    }
};
