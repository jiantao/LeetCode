/*
 * =====================================================================================
 *
 *       Filename:  roman_to_integer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2013 09:06:09 PM
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
    Solution()
    {
        buildMap();
    }

    int romanToInt(string s) 
    {
        int len = s.length();
        int result = 0;

        int i = 0;
        for (; i < len - 1;)
        {
            if (map[s[i] - 'A'] >= map[s[i+1] - 'A'])
            {
                result += map[s[i] - 'A'];
                ++i;
            }
            else
            {
                result += map[s[i+1] - 'A'] - map[s[i] - 'A'];
                i += 2;
            }
        }

        if (i == len - 1)
            result += map[s[i] - 'A'];

        return result;
    }

private:
    void buildMap(void)
    {
        memset(map, 0, 26 * sizeof(int));
        map['M' - 'A'] = 1000;
        map['D' - 'A'] = 500;
        map['C' - 'A'] = 100;
        map['L' - 'A'] = 50;
        map['X' - 'A'] = 10;
        map['V' - 'A'] = 5;
        map['I' - 'A'] = 1;
    }

private:
    int map[26];
};
