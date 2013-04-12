/*
 * =====================================================================================
 *
 *       Filename:  is_interleave_str.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/13 11:54:40
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
    bool isInterleave(string s1, string s2, string s3) 
    {
        int strLen1 = s1.length();
        int strLen2 = s2.length();
        int strLen3 = s3.length();

        if (strLen3 != strLen1 + strLen2)
            return false;

        if (strLen1 == 0 && strLen2 == 0)
            return true;
        else if (strLen1 != 0 && strLen2 == 0)
        {
            if (s1 == s3)
                return true;
            else
                return false;
        }
        else if (strLen1 == 0 && strLen2 != 0)
        {
            if (s2 == s3)
                return true;
            else
                return false;
        }

        table.resize(strLen1 + 1);
        for (int i = 0; i <= strLen1; ++i)
            table[i].resize(strLen2 + 1);

        table[0][0] = 1;
        for (int i = 1; i <= strLen1; ++i)
        {
            table[i][0] = 0;
            if (s1[i-1] == s3[i-1])
                table[i][0] += table[i-1][0];
        }

        for (int i = 1; i <= strLen2; ++i)
        {
            table[0][i] = 0;
            if (s2[i-1] == s3[i-1])
                table[0][i] += table[0][i-1];
        }

        for (int i = 1; i <= strLen1; ++i)
        {
            for (int j = 1; j <= strLen2; ++j)
            {
                table[i][j] = 0;
                if (s1[i-1] == s3[i+j-1])
                    table[i][j] += table[i-1][j];

                if (s2[j-1] == s3[i+j-1])
                    table[i][j] += table[i][j-1];
            }
        }

        if (table[strLen1][strLen2] > 0)
            return true;
        else
            return false;
    }

private:
    vector<vector<int> > table;
};
