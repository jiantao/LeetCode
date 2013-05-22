/*
 * =====================================================================================
 *
 *       Filename:  subset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2013 01:52:24 PM
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
    vector<vector<int> > subsets(vector<int> &S) 
    {
        results.clear();
        tempResults.clear();

        std::sort(S.begin(), S.end());
        size = S.size();
        for (int i = 0; i <= size; ++i)
            dfs(S, i, 0);

        return results;
    }

private:
    void dfs(const vector<int>& S, int numLeft, int idx)
    {
        if (numLeft == 0)
        {
            results.push_back(tempResults);
            return;
        }

        int remains = size - idx - 1; 
        int pushCount = 0;
        for (int i = 0; i <= 1; ++i)
        {
            if (numLeft < i)
                break;

            if (i > 0)
            {
                tempResults.push_back(S[idx]);
                ++pushCount;
            }

            if (numLeft > remains + i)
                continue;

            dfs(S, numLeft - i, idx + 1);
        }

        for (int i = 0; i != pushCount; ++i)
            tempResults.pop_back();
    }

private:
    int size;
    vector<int> tempResults;
    vector<vector<int> > results;
};

class SolutionDup
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
        results.clear();
        tempResults.clear();

        std::sort(S.begin(), S.end());
        size = S.size();
        for (int i = 0; i <= size; ++i)
            dfs(S, i, 0);

        return results;
    }

private:
    void dfs(const vector<int>& S, int numLeft, int idx)
    {
        if (numLeft == 0)
        {
            results.push_back(tempResults);
            return;
        }

        int remains = size - idx - 1; 
        int pushCount = 0;
        for (int i = 0; i <= 1; ++i)
        {
            if (numLeft < i)
                break;

            if (i > 0)
            {
                tempResults.push_back(S[idx]);
                ++pushCount;
            }

            if (numLeft > remains + i)
                continue;

            dfs(S, numLeft - i, idx + 1);
        }

        for (int i = 0; i != pushCount; ++i)
            tempResults.pop_back();
    }

private:
    int size;
    vector<int> tempResults;
    vector<vector<int> > results;
};

class Solution2
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
        result.clear();
        int size = S.size();
        std::sort(S.begin(), S.end());
        unsigned target = pow(2, size);
        unsigned curr = 0;

        vector<int> temp;
        while (curr != target)
        {
            temp.clear();
            int idx = 0;
            int currTemp = curr;
            while (currTemp != 0)
            {
                if ((currTemp & 1) != 0)
                    temp.push_back(S[idx]);

                currTemp = currTemp >> 1;
                ++idx;
            }

            result.push_back(temp);
            ++curr;
        }

        return result;
    }

private:
    vector<vector<int>> result;
};

class Solution3
{
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
        result.clear();
        int size = S.size();
        std::sort(S.begin(), S.end());

        result.push_back(vector<int>());

        for (int i = 0; i != size; ++i)
        {
            int subSize = result.size();
            for (int j = 0; j != subSize; ++j)
            {
                vector<int> temp(result[j]);
                temp.push_back(S[i]);
                result.push_back(temp);
            }
        }
        return result;
    }

private:
    vector<vector<int>> result;
};
