/*
 * =====================================================================================
 *
 *       Filename:  two_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 09:48:27 PM
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
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        hash.clear();
        result.resize(2, 0);
        int size = numbers.size();

        for (int i = 0; i != size; ++i)
        {
            hash[numbers[i]].idx = i + 1;
            hash[numbers[i]].count += 1;
        }

        for (int i = 0; i != size; ++i)
        {
            int left = target - numbers[i];
            unordered_map<int, Index>::iterator iter;
            if ((iter = hash.find(left)) != hash.end())
            {
                if (left != numbers[i])
                {
                    result[0] = i + 1;
                    result[1] = iter->second.idx;
                    return result;
                }
                else
                {
                    if (iter->second.count > 1)
                    {
                        result[0] = i + 1;
                        result[1] = iter->second.idx;
                        return result;
                    }
                }
            }
        }
    }

private:
    struct Index
    {
        int idx;
        int count;

        Index() : idx(0), count(0) {}
    };

    unordered_map<int, Index> hash;
    vector<int> result;
};
