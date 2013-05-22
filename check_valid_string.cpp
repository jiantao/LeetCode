/*
 * =====================================================================================
 *
 *       Filename:  check_valid_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/21/2013 09:26:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

// some of the upper case characters are accidentally lowered.
// write a algorithm to find the right string. String length is 22.

#include "header.hpp"

using namespace std;

class Solution
{
public:

    Solution() : rightStr("abcdefGhijkLmnoPqrsTUV") {}

    string checkValidString(string& wrongStr)
    {
        unsigned int target = pow(2, 22);
        unsigned int currSet = 0;

        while (currSet != target)
        {
            unsigned temp = currSet;
            int i = 0;
            string test(wrongStr);
            while (temp != 0)
            {
                if (temp & 1)
                    test[i] = toupper(test[i]);

                temp = temp >> 1;
                ++i;
            }

            if (isValidStr(test))
                return test;

            ++currSet;
        }

        return wrongStr;
    }

private:
    bool isValidStr(const string& test)
    {
        return test == rightStr;
    }

private:
    const string rightStr;
};

int main(int argc, char *argv[])
{
    Solution solution;
    
    string wrong("abcdefghijklmnopqrstuv");
    cout << solution.checkValidString(wrong) << endl;
    return 0;
}
