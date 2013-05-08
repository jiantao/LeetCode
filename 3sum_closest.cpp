/*
 * =====================================================================================
 *
 *       Filename:  3sum_closest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/07/2013 11:48:27 PM
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
    int threeSumClosest(vector<int> &num, int target) 
    {
        int closest = 0;
        int minDiff = INT_MAX;
        int size = num.size();
        sort(num.begin(), num.end());

        int prevOne = num[0] - 1;
        for (int i = 0; i < size - 2; ++i)
        {
            if (prevOne == num[i])
                continue;

            int prevTwo = num[0] - 1;
            int last = size - 1;
            for (int j = i + 1; j < size - 1; ++j)
            {
                if (prevTwo == num[j])
                    continue;

                while (last > j)
                {
                    int sum = num[i] + num[j] + num[last];
                    int diff = sum - target;
                    if (abs(diff) < minDiff)
                    {
                        closest = sum;
                        minDiff = abs(diff);
                    }

                    if (diff <  0)
                        break;
                    else if (diff == 0)
                        return sum;

                    --last;
                }

                if (last <= j)
                    break;

                prevTwo = num[j];
            }

            prevOne = num[i];
        }

        return closest;
    }
};

int main(int argc, char *argv[])
{
    int test[] = {0, 1, 2, 3, 4, 5};
    vector<int> input(test, test + 6);
    Solution solution;

    cout << solution.threeSumClosest(input, 13) << endl;
    return 0;
}
