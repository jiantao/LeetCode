/*
 * =====================================================================================
 *
 *       Filename:  multiply_strings.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/2013 05:45:33 PM
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
    string multiply(string num1, string num2) 
    {
        int l1 = num1.length();
        int l2 = num2.length();
        vector<int> result(l1 + l2, 0);

        for (int i = 0; i != l1; ++i)
        {
            int d1 = num1[l1-i-1] - '0';
            int carry = 0;
            for (int j = 0; j != l2; ++j)
            {
                int d2 = num2[l2-j-1] - '0';
                int temp = d1 * d2 + carry + result[i+j];
                result[i+j] = temp % 10;
                carry = temp / 10;
            }

            result[i+l2] += carry;
        }

        int start = l1 + l2 - 1;
        while (start > 0 && result[start] == 0)
            --start;

        string ret("");
        for (int i = start; i >= 0; --i)
            ret.push_back('0' + result[i]);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    string s1 = "1";
    string s2 = "0";

    Solution solution;
    string result = solution.multiply(s1, s2);

    cout << result << endl;

    return 0;
}
