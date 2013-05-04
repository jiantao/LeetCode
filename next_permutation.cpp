/*
 * =====================================================================================
 *
 *       Filename:  next_permutation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/02/2013 11:15:34 PM
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
    void nextPermutation(vector<int> &num) 
    {
        int size = num.size();
        int i = 0;
        for (i = size - 1; i > 0; --i)
        {
            if (num[i] > num[i-1])
                break;
        }

        if (i != 0)
        {
            for (int j = size - 1; j > 0; --j)
            {
                if (num[j] > num[i-1])
                {
                    swap(num[j], num[i-1]);
                    reverse(num.begin() + i, num.end());
                    break;
                }
            }
        }
        else
            reverse(num.begin(), num.end());
    }
};

int main(int argc, char *argv[])
{
    int test[] = {1, 5, 3, 4, 2};
    vector<int> num(test, test + 5);

    Solution solution;
    solution.nextPermutation(num);

    for (unsigned i = 0; i != num.size(); ++i)
        cout << num[i] << endl;

    return 0;
}
