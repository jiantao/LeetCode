/*
 * =====================================================================================
 *
 *       Filename:  permutation_sequence.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/13 09:54:21
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
    Solution()
    {
        calNumPerm();
    }

    string getPermutation(int n, int k) 
    {
        string result("");
        for (int i = 0; i != 9; ++i)
            digits[i] = i + 1;

        int left = k;
        int lv = n - 1;
        while (lv >= 0)
        {
            int num = (left - 1) / numPerm[lv] + 1;
            result += getNextDigit(num);
            left = left % numPerm[lv];

            if (left == 0)
                left = numPerm[lv];

            --lv;
        }

        return result;
    }

private:
    void calNumPerm()
    {
        numPerm.resize(10, 1);
        for (int i = 2; i < 10; ++i)
            numPerm[i] = numPerm[i-1] * ii;

        digits.resize(9);
    }

    char getNextDigit(int num)
    {
        unsigned i;
        int count = 0;
        for (i = 0; i != digits.size(); ++i)
        {
            if (digits[i] > 0)
                ++count;

            if (count == num)
            {
                char ret =  '0' + digits[i];
                digits[i] = -1;
                return ret;
            }
        }
    }

private:
    vector<int> numPerm;
    vector<int> digits;
};
