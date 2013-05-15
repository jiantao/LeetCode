/*
 * =====================================================================================
 *
 *       Filename:  equilibrium_index.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/15/13 11:58:04
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
    vector<int> findEquilibriumIndex(vector<int>& nums)
    {
        result.clear();
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i != size; ++i)
            sum += nums[i];

        int tempSum = 0;
        for (int i = 0; i < size - 1; ++i)
        {
            tempSum += nums[i];
            if (tempSum == sum - tempSum - nums[i+1])
                result.push_back(i+1);
        }

        return result;
    }

private:
    vector<int> result;
};

int main(int argc, char *argv[])
{
    int test[] = {-7, 1, 5, 2, -4, 3, 0};
    vector<int> input(test, test + 7);

    Solution solution;
    vector<int> result = solution.findEquilibriumIndex(input);

    for (unsigned i = 0 ; i != result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
