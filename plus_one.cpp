/*
 * =====================================================================================
 *
 *       Filename:  plus_one.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2013 10:48:31 PM
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
    vector<int> plusOne(vector<int> &digits) 
    {
        int size = digits.size();
        bool addOne = true;
        for (int i = size - 1; i >= 0; --i)
        {
            if (!addOne)
                break;

            if (digits[i] != 9)
            {
                ++digits[i];
                addOne = false;
            }
            else
                digits[i] = 0;
        }

        if (addOne)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main(int argc, char *argv[])
{
    vector<int> digits(1, 9);
    Solution solution;

    solution.plusOne(digits);

    for (unsigned i = 0; i != digits.size(); ++i)
        cout << digits[i];

    cout << endl;
    return 0;
}
