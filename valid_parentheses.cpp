/*
 * =====================================================================================
 *
 *       Filename:  valid_parentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 11:25:55 PM
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
    bool isValid(string s) 
    {
        stack.clear();
        int sLen = s.length();
        for (int i = 0 ; i != sLen; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push_back(s[i]);
            else
            {
                if (stack.empty())
                    return false;

                switch (s[i])
                {
                    case ')':
                        if (stack.back() != '(')
                            return false;
                        break;
                    case ']':
                        if (stack.back() != '[')
                            return false;
                        break;
                    case '}':
                        if (stack.back() != '{')
                            return false;
                        break;
                    default:
                        return false;
                        break;
                }

                stack.pop_back();
            }
        }

        if (stack.empty())
            return true;
        else
            return false;
    }

private:
    vector<char> stack;
};
