/*
 * =====================================================================================
 *
 *       Filename:  letter_combination.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 01:24:50 PM
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
        pad.resize(10);
        pad[0] = " ";
        pad[1] = "";
        pad[2] = "abc";
        pad[3] = "def";
        pad[4] = "ghi";
        pad[5] = "jkl";
        pad[6] = "mno";
        pad[7] = "pqrs";
        pad[8] = "tuv";
        pad[9] = "wxyz";
    }

    vector<string> letterCombinations(string digits) 
    {
        result.clear();
        temp.clear();
        doCombination(digits, 0);
        return result;
    }

    void doCombination(const string& digits, int idx)
    {
        if (idx == (int) digits.length())
        {
            result.push_back(temp);
            return;
        }

        const string& padStr = pad[digits[idx] - '0'];
        int len = padStr.length();
        for (int i = 0; i != len; ++i)
        {
            temp.push_back(padStr[i]);
            doCombination(digits, idx + 1);
            temp.erase(temp.size() - 1);
        }
    }

private:
    string temp;
    vector<string> pad;
    vector<string> result;
};
