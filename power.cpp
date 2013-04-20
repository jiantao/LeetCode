/*
 * =====================================================================================
 *
 *       Filename:  power.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2013 06:36:57 PM
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

class Solution {
public:
    double pow(double x, int n) 
    {
        base = x;
        if (n >= 0)
            return powHelper(n);
        else
            return 1.0 / powHelper(-n);
    }

private:

    double powHelper(int n)
    {
        if (n == 0)
            return 1;

        double v = powHelper(n / 2);
        if (n % 2 == 0)
            return v * v;
        else
            return v * v * base;
    }

private:
    double base;
};
