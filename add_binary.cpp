/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2013 11:09:38 PM
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
    string addBinary(string a, string b) 
    {
        int aLen = a.length();
        int bLen = b.length();

        int sLen = 0;
        int lLen = 0;
        string result;
        if (aLen < bLen)
        {
            sLen = aLen;
            lLen = bLen;
            result.assign(b);
        }
        else
        {
            sLen = bLen;
            lLen = aLen;
            result.assign(a);
        }

        int prom = 0;
        for (int i = aLen - 1, j = bLen - 1, k = sLen - 1, h = lLen - 1; k >= 0; --i, --j, --k, --h)
        {
            char c = '0' + prom;
            if (a[i] == '1' && b[j] == '1')
                prom = 1;
            else if (a[i] == '0' && b[j] == '0')
                prom = 0;
            else
            {
                if (c == '0')
                {
                    c = '1';
                    prom = 0;
                }
                else
                {
                    c = '0';
                    prom = 1;
                }
            }

            result[h] = c;
        }

        for (int i = lLen - sLen - 1; i >= 0; --i)
        {
            if (prom == 1)
            {
                if (result[i] == '0')
                {
                    result[i] = '1';
                    prom = 0;
                }
                else
                {
                    result[i] = '0';
                    prom = 1;
                }
            }
            else
                break;
        }

        if (prom == 1)
            result = "1" + result;

        return result;
    }
};
