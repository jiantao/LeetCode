/*
 * =====================================================================================
 *
 *       Filename:  combination_sum2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 12:13:01 AM
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
    struct Point
    {
        int num;
        int count;

        Point(int a, int b) : num(a), count(b) {}
    };

    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        nums.clear();
        temp.clear();
        hash.clear();
        results.clear();

        n = num.size();
        for (int i = 0; i != n; ++i)
            ++hash[num[i]];

        map<int, int>::iterator iter;
        for (iter = hash.begin(); iter != hash.end(); ++iter)
            nums.push_back(Point(iter->first, iter->second));

        doSum(nums, 0, target);
        return results;
    }

private:

    void doSum(const vector<Point>& nums, int idx, int target)
    {
        if (target == 0)
        {
            results.push_back(temp);
            return;
        }

        if (idx == n)
            return;

        int count = 0;
        doSum(nums, idx + 1, target);
        for (int i = 1; nums[idx].count - i >= 0 && target - nums[idx].num * i >= 0; ++i)
        {
            ++count;
            temp.push_back(nums[idx].num);
            doSum(nums, idx + 1, target - nums[idx].num * i);
        }

        for (int i = 0; i != count; ++i)
            temp.pop_back();
    }

private:
    int n;
    vector<Point> nums;
    vector<int> temp;
    map<int, int> hash;
    vector<vector<int>> results;
};


int main(int argc, char *argv[])
{
    int test[] = {3, 1, 3, 5, 1, 1};
    vector<int> can(test, test + 6);
    int target = 8;

    Solution solution;
    vector<vector<int>> results = solution.combinationSum2(can, target);

    for (unsigned i = 0; i != results.size(); ++i)
    {
        for (unsigned j = 0; j != results[i].size(); ++j)
            cout << results[i][j] << "\t";

        cout << endl;
    }
    return 0;
}
