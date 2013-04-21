/*
 * =====================================================================================
 *
 *       Filename:  n_queens.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2013 03:28:11 PM
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
    vector<vector<string> > solveNQueens(int n) 
    {
        result.clear();
        upperLimit = (1 << n) - 1;

        compute(0, 0, 0);
        return result;
    }

private:
    void compute(long row, long ld, long rd)
    {
        if (row != upperLimit)
        {
            long pos = upperLimit & ~(row | ld | rd);
            while (pos != 0)
            {
                long p = pos & -pos;
                pos -= p;
                temp.push_back(log2(p));
                compute(row + p, (ld + p) << 1, (rd + p) >> 1);
                temp.pop_back();
            }
        }
        else
        {
            pushResult();
        }
    }

    void pushResult(void)
    {
        int size = temp.size();
        vector<string> one;
        string row(size, '.');
        for (int i = 0; i != size; ++i)
        {
            int idx = size - temp[i] - 1;
            row[idx] = 'Q';
            one.push_back(row);
            row[idx] = '.';
        }

        result.push_back(one);
    }

private:
    long upperLimit;
    vector<int> temp;
    vector<vector<string> > result;
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<vector<string> > result = solution.solveNQueens(4);

    for (unsigned i = 0; i != result.size(); ++i)
    {
        for (unsigned j = 0; j != result[i].size(); ++j)
            cout << result[i][j] << "\n";

        cout << "\n";
    }

    return 0;
}
