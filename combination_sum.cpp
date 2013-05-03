/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/2013 10:34:01 PM
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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        results.clear();
        temp.clear();
        hash.clear();
        n = candidates.size();

        for (int i = 0; i != n; ++i)
            hash.insert(candidates[i]);

        nums.assign(hash.begin(), hash.end());
        doSum(nums, 0, target);

        return results;
    }

private:

    void doSum(vector<int>& candidates, int idx, int target)
    {
        if (target == 0)
        {
            results.push_back(temp);
            return;
        }

        if (idx == n)
            return;

        int count = 0;
        doSum(candidates, idx + 1, target);
        for (int i = 1; target - i * candidates[idx] >= 0; ++i)
        {
            ++count;
            temp.push_back(candidates[idx]);
            doSum(candidates, idx + 1, target - i * candidates[idx]);
        }

        for (int j = 0; j != count; ++j)
            temp.pop_back();
    }


private:
    int n;
    vector<int> temp;
    vector<int> nums;
    set<int> hash;
    vector<vector<int>> results;
};

int main(int argc, char *argv[])
{
    int test[] = {8, 7, 4, 3};
    vector<int> can(test, test + 4);
    int target = 11;

    Solution solution;
    vector<vector<int>> results = solution.combinationSum(can, target);

    for (unsigned i = 0; i != results.size(); ++i)
    {
        for (unsigned j = 0; j != results[i].size(); ++j)
            cout << results[i][j] << "\t";

        cout << endl;
    }
    return 0;
}
