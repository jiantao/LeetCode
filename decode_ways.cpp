/*
 * =====================================================================================
 *
 *       Filename:  decode_ways.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2013 10:26:31 PM
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
    int numDecodings(string s) 
    {
        int strLen = s.length();
        if (strLen == 0)
            return 0;

        counts.clear();
        counts.resize(strLen + 1);

        counts[0] = 1;
        if (s[0] != '0') 
            counts[1] = 1;
        else
            return 0;

        for (int i = 2; i <= strLen; ++i)
        {
            counts[i] = 0;
            if (s[i-1] != '0') 
                counts[i] += counts[i-1];

            if (s[i-2] != '0' && atoi(s.substr(i - 2, 2).c_str()) <= 26)
                counts[i] += counts[i-2];

            if (counts[i] == 0)
                return 0;
        }

        return counts[strLen];
    }

private:

    vector<int> counts;
};
