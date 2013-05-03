/*
 * =====================================================================================
 *
 *       Filename:  longest_valid_parentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/01/2013 11:16:11 PM
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
    int longestValidParentheses(string s) 
    {
        stack.clear();
        posStack.clear();
        int sLen = s.length();
        for (int i = 0; i != sLen; ++i)
        {
            if (s[i] == '(')
            {
                stack.push_back(s[i]);
                posStack.push_back(i);
            }
            else
            {
                if (stack.back() == '(')
                {
                    stack.pop_back();
                    posStack.pop_back();
                }
                else
                {
                    stack.push_back(s[i]);
                    posStack.push_back(i);
                }
            }
        }

        int longest = 0;
        int last = 0;
        int left = posStack.size();
        for (int i = 0; i != left; ++i)
        {
            int len = posStack[i] - last;
            if (len > longest)
                longest = len;

            last = posStack[i] + 1;
        }

        int len = sLen - last;
        if (len > longest)
            longest = len;

        return longest;
    }


private:
    vector<int> posStack;
    vector<char> stack;
};

int main(int argc, char *argv[])
{
    string test = "(()()";

    Solution solution;

    cout << solution.longestValidParentheses(test) << endl;
    return 0;
}
