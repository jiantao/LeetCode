/*
 * =====================================================================================
 *
 *       Filename:  subset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2013 04:35:15 PM
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
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
        results.clear();
        preprocess(S);

        int size = S.size();
        for (int i = 0; i <= size; ++i)
            dfs(i, 0);

        return results;
    }

private:

    void preprocess(const vector<int>& S)
    {
        elements.clear();
        candidates.clear();
        cumSum.clear();

        int origSize = S.size();
        for (int i = 0; i != origSize; ++i)
            ++(elements[S[i]]);

        map<int, int>::const_iterator iter;
        int cum = 0;
        for (iter = elements.begin(); iter != elements.end(); ++iter)
        {
            candidates.push_back(Element(iter->first, iter->second));
            cum += iter->second;
            cumSum.push_back(cum);
        }

        elements.clear();
    }

    void dfs(int numLeft, int idx)
    {
        if (numLeft == 0)
        {
            results.push_back(tempResult);
            return;
        }

        int remaining = cumSum.back() - cumSum[idx];
        int numElement = candidates[idx].count;
        int pushCount = 0;
        for (int i = 0; i <= numElement; ++i)
        {
            if (i > numLeft)
                break;
            
            if (i > 0)
            {
                tempResult.push_back(candidates[idx].num);
                ++pushCount;
            }

            if (remaining + i < numLeft)
                continue;

            dfs(numLeft - i, idx + 1);
        }

        for (int i = 0; i != pushCount; ++i)
            tempResult.pop_back();
    }

private:

    struct Element
    {
        int num;
        int count;

        Element(int n, int c) : num(n), count(c) {};
    };

    map<int, int> elements;
    vector<Element> candidates;
    vector<int> cumSum;
    vector<int> tempResult;
    vector<vector<int> > results;
};
