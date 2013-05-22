/*
 * =====================================================================================
 *
 *       Filename:  random_on_weight.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2013 10:32:39 PM
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

    // the value of each number is its weight
    // return a random number with a probability
    // proportional to its value
    int randomOnWeight(vector<int>& nums)
    {
        int sum = 0;
        int size = nums.size();

        for (int i = 0; i != size; ++i)
            sum += nums[i];

        double randNum = (double) rand() / RAND_MAX * sum;
        for (int i = 0; i != size; ++i)
        {
            randNum -= nums[i];
            if (randNum < 0)
                return nums[i];
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{
    vector<int> test(100, 0);
    for (int i = 1; i <= 100; ++i)
        test[i-1] = i;

    Solution solution;

    for (int i = 0; i != 100000; ++i)
        cout << solution.randomOnWeight(test) << "\n";

    return 0;
}
