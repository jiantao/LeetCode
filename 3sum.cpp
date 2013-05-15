/*
 * =====================================================================================
 *
 *       Filename:  3sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 11:03:19 PM
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
    vector<vector<int>> threeSum(vector<int> &num) 
    {
        result.clear();
        sort(num.begin(), num.end());
        int size = num.size();
        if (size < 3)
            return result;

        int prevOne = num[0] - 1;
        for (int i = 0; i <= size - 3; ++i)
        {
            if (prevOne == num[i])
                continue;

            int prevTwo = num[0] - 1;
            int last = size - 1;
            for (int j = i + 1; j <= size - 2; ++j)
            {
                if (prevTwo == num[j])
                    continue;

                int sum = num[i] + num[j];
                bool isFound = false;
                while (last > j && sum + num[last] >= 0)
                {
                    if (sum + num[last] == 0 && !isFound)
                    {
                        int test[] = {num[i], num[j], num[last]};
                        result.push_back(vector<int>(test, test + 3));
                        isFound = true;
                    }

                    --last;
                }

                if (last == j)
                    break;

                prevTwo = num[j];
            }

            prevOne = num[i];
        }

        return result;
    }

private:
    
    vector<vector<int>> result;
};

class SolutionDup
{
public:
    vector<vector<int>> threeSum(vector<int> &num) 
    {
        result.clear();
        int size = num.size();
        if (size == 0)
            return result;

        sort(num.begin(), num.end());

        int prevOne = num[0] - 1;
        for (int i = 0; i <= size - 3; ++i)
        {
            if (prevOne == num[i])
                continue;

            int last = size - 1;
            int prevTwo = num[0] - 1;
            for (int j = i + 1; j <= size - 2; ++j)
            {
                if (prevTwo == num[j])
                    continue;

                while (last > j)
                {
                    int sum = num[i] + num[j] + num[last];
                    if (sum < 0)
                        break;
                    else if (sum == 0)
                    {
                        int temp[] = {num[i], num[j], num[last]};
                        result.push_back(vector<int>(temp, temp + 3));
                        break;
                    }

                    --last;
                }

                if (last == j)
                    break;

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
    int t[] = {-2, 0, 0, 2, 2};
    vector<int> test(t, t + 5);
    SolutionDup solution;
    
    vector<vector<int>> result = solution.threeSum(test);

    for (unsigned i = 0 ; i != result.size(); ++i)
    {
        for (unsigned j = 0; j != result[i].size(); ++j)
            cout << result[i][j] << "\t";

        cout << endl;
    }
    return 0;
}
