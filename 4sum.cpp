/*
 * =====================================================================================
 *
 *       Filename:  4sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 06:15:05 PM
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
    vector<vector<int> > fourSum(vector<int> &num, int target) 
    {
        result.clear();
        int size = num.size();
        if (size < 4)
            return result;

        sort(num.begin(), num.end());

        int prevOne = num[0] - 1;
        for (int i = 0; i <= size - 4; ++i)
        {
            if (prevOne == num[i])
                continue;

            int prevTwo = num[0] - 1;
            for (int j = i + 1; j <= size - 3; ++j)
            {
                if (prevTwo == num[j])
                    continue;

                int prevThree = num[0] - 1;
                int last = size - 1;
                for (int k = j + 1; k <= size - 2; ++k)
                {
                    if (prevThree == num[k])
                        continue;
                    
                    bool isFound = false;
                    while (last > k )
                    {
                        int sum = num[i] + num[j] + num[k] + num[last];
                        if (sum < target)
                            break;

                        if (sum == target && !isFound)
                        {
                            int temp[] = {num[i], num[j], num[k], num[last]};
                            result.push_back(vector<int>(temp, temp + 4));
                            isFound = true;
                        }

                        --last;
                    }

                    if (last <= k)
                        break;

                    prevThree = num[k];
                }

                prevTwo = num[j];
            }

            prevOne = num[i];
        }

        return result;
    }

private:
    vector<vector<int>> result;
};


int main(int argc, char *argv[])
{
    int test[] = {1, 0, -1, 0, -2, 2};
    vector<int> input(test, test + 6);

    Solution solution;

    vector<vector<int>> result = solution.fourSum(input, 0);

    cout << endl;
    for (unsigned i = 0; i != result.size(); ++i)
    {
        for (unsigned j = 0; j != result[i].size(); ++j)
            cout << result[i][j] << "\t";

        cout << endl;
    }
    return 0;
}
