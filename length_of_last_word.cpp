/*
 * =====================================================================================
 *
 *       Filename:  length_of_last_word.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/13 14:41:30
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
    int lengthOfLastWord(const char *s) 
    {
        int len = strlen(s);
        if (len == 0)
            return 0;

        int i = len - 1;
        while (i >= 0 && s[i] == ' ')
            --i;

        if (i < 0)
            return 0;

        int j = i;
        while (j >= 0 && s[j] != ' ')
            --j;

        return i - j;
    }
};
