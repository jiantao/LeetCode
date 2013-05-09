/*
 * =====================================================================================
 *
 *       Filename:  longest_common_prefix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2013 06:27:32 AM
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
    string longestCommonPrefix(vector<string> &strs) 
    {
        result.clear();

        int size = strs.size();
        if (size == 0)
            return result;

        int firstLen = strs[0].length();
        for (int i = 0; i != firstLen; ++i)
        {
            char target = strs[0][i];
            bool isCommon = true;
            for (int j = 1; j != size; ++j)
            {
                if (i >= (int) strs[j].length() || strs[j][i] != target)
                {
                    isCommon = false;
                    break;
                }
            }

            if (!isCommon)
                break;

            result += target;
        }

        return result;
    }

private:
    string result;
};
