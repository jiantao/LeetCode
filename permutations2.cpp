/*
 * =====================================================================================
 *
 *       Filename:  permutations2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2013 11:50:39 PM
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
    vector<vector<int> > permuteUnique(vector<int> &num) 
    {
        result.clear();
        n = num.size();
        temp.resize(n);
        for (int i = 0; i != n; ++i)
            ++uniqMap[num[i]];

        compute(0);

        return result;
    }

private:

    void compute(int idx)
    {
        if (idx != n)
        {
            unordered_map<int, int>::iterator iter;
            for (iter = uniqMap.begin(); iter != uniqMap.end(); ++iter)
            {
                if (iter->second > 0)
                {
                    --(iter->second);
                    temp[idx] = iter->first;
                    compute(idx + 1);
                    ++(iter->second);
                }
            }
        }
        else
            result.push_back(temp);
    }

private:

    int n;
    vector<int> temp;
    vector<vector<int>> result;
    unordered_map<int, int> uniqMap;
};

int main(int argc, char *argv[])
{
    vector<int> num;
    for (int i = 0; i != 4; ++i)
        num.push_back(1);

    num[0] = 2;
    num[1] = 2;


    Solution solution;
    vector<vector<int>> result = solution.permuteUnique(num);

    for (unsigned i = 0; i != result.size(); ++i)
    {
        for (unsigned j = 0; j != result[i].size(); ++j)
            cout << result[i][j] << "\t";

        cout << endl;
    }
    return 0;
}
