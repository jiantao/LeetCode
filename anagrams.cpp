/*
 * =====================================================================================
 *
 *       Filename:  anagrams.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2013 07:28:14 PM
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
    vector<string> anagrams(vector<string> &strs) 
    {
        hash.clear();
        result.clear();
        int numStr = strs.size();
        for (int i = 0; i != numStr; ++i)
        {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());
            hash[temp].push_back(i);
        }

        unordered_map<string, vector<int>>::iterator iter;
        for (iter = hash.begin(); iter != hash.end(); ++iter)
        {
            int n = iter->second.size();
            if (n > 1)
            {
                for (int i = 0; i != n; ++i)
                    result.push_back(strs[iter->second[i]]);
            }
        }

        return result;
    }

private:
    unordered_map<string, vector<int>> hash;
    vector<string> result;
};
