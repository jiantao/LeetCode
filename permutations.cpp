/*
 * =====================================================================================
 *
 *       Filename:  permutations.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2013 11:14:06 PM
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
    vector<vector<int> > permute(vector<int> &num) 
    {
        result.clear();
        int n = num.size();
        upperLimit = (1 << n) - 1;
        temp.resize(n);

        compute(num, 0, 0);
        return result;
    }

private:
    void compute(const vector<int>& num, long row, int which)
    {
        if (row != upperLimit)
        {
            long pos = upperLimit & (~row);
            while (pos != 0)
            {
                long p = pos & -pos;
                pos -= p;
                int where = log2(p);
                temp[where] = num[which];
                compute(num, row + p, which + 1);
            }
        }
        else
            result.push_back(temp);
    }

private:

    long upperLimit;
    vector<int> temp;
    vector<vector<int>> result;
};

class Solution2
{
public:
    vector<vector<int> > permute(vector<int> &num) 
    {
        result.clear();
        n = num.size();

        compute(num, 0);
        return result;
    }

private:

    void compute(vector<int>& num, int idx)
    {
        if (idx == n)
        {
            result.push_back(num);
            return;
        }

        for (int i = idx; i != n; ++i)
        {
            swap(num[i], num[idx]);
            compute(num, idx + 1);
            swap(num[i], num[idx]);
        }
    }

private:

    int n;
    vector<int> temp;
    vector<vector<int>> result;
};

int main(int argc, char *argv[])
{
    vector<int> num;
    for (int i = 0; i != 4; ++i)
        num.push_back(i + 1);

    Solution2 solution;
    vector<vector<int>> result = solution.permute(num);

    for (unsigned i = 0; i != result.size(); ++i)
    {
        for (unsigned j = 0; j != result[i].size(); ++j)
            cout << result[i][j] << "\t";

        cout << endl;
    }
    return 0;
}
