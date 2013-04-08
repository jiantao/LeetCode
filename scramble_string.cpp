/*
 * =====================================================================================
 *
 *       Filename:  scramble_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/07/2013 02:05:17 PM
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
    bool isScramble(string s1, string s2) 
    {
        charMap.resize(26, 0);
        int strLen = s1.length();
        
        return checkScramble(s1, s2, 0, 0, strLen);
    }

private:
    bool checkScramble(const string& s1, const string& s2, int start1, int start2, int len)
    {
        if (len == 1)
            return s1[start1] == s2[start2];

        for (int i = 1; i <= len / 2; ++i)
        {
            int aLen = i;
            int a1 = start1;
            int a2 = start2;

            int bLen = len - i;
            int b1 = start1 + i;
            int b2 = start2 + i;

            bool result = false;

            if (checkCharSet(s1, s2, a1, a2, aLen)
                && checkCharSet(s1, s2, b1, b2, bLen))
            {
                result = checkScramble(s1, s2, a1, a2, aLen) 
                         && checkScramble(s1, s2, b1, b2, bLen);

                if (result) return true;
            }

            int xLen = bLen;
            int x1 = start1;
            int x2 = start2;

            int yLen = aLen;
            int y1 = start1 + xLen;
            int y2 = start2 + xLen;

            if (checkCharSet(s1, s2, x1, x2, xLen)
                && checkCharSet(s1, s2, y1, y2, yLen))
            {
                result = checkScramble(s1, s2, x1, x2, xLen) 
                         && checkScramble(s1, s2, y1, y2, yLen);

                if (result) return true;
            }

            if (checkCharSet(s1, s2, a1, y2, aLen)
                && checkCharSet(s1, s2, b1, x2, bLen))
            {
                result = checkScramble(s1, s2, a1, y2, aLen) 
                         && checkScramble(s1, s2, b1, x2, bLen);

                if (result) return true;
            }

            if (checkCharSet(s1, s2, x1, b2, xLen)
                && checkCharSet(s1, s2, y1, a2, yLen))
            {
                result = checkScramble(s1, s2, x1, b2, xLen) 
                         && checkScramble(s1, s2, y1, a2, yLen);

                if (result) return true;
            }
        }

        return false;
    }

    bool checkCharSet(const string& s1, const string& s2, int start1, int start2, int len)
    {
        charMap.assign(26, 0);
        for (int i = 0; i != len; ++i)
            ++charMap[s1[start1 + i] - 'a'];

        for (int i = 0; i != len; ++i)
        {
            if (charMap[s2[start2 + i] - 'a'] == 0)
                return false;

            --charMap[s2[start2 + i] - 'a'];
        }

        return true;
    }

private:
    vector<int> charMap;
};
