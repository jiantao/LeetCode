/*
 * =====================================================================================
 *
 *       Filename:  simplify_path.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2013 12:02:47 AM
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
    string simplifyPath(string path) 
    {
        int len = path.length();
        if (len <= 1)
            return path;

        charStack.clear();

        for (int i = 0; i != len; ++i)
        {
            switch (path[i])
            {
                case '/':
                    if (charStack.back() == '.')
                        charStack.pop_back();

                    if (charStack.back() != '/')
                        charStack.push_back(path[i]);
                    break;

                case '.':
                    if (charStack.back() == '.')
                    {
                        charStack.pop_back();
                        if (charStack.size() > 1)
                        {
                            charStack.pop_back();
                            while (charStack.back() != '/')
                                charStack.pop_back();
                        }
                    }
                    else
                        charStack.push_back(path[i]);

                    break;
                default:
                    charStack.push_back(path[i]);
                    break;
            }
        }

        if (charStack.back() == '.')
            charStack.pop_back();
            
        if (charStack.back() == '/' && charStack.size() > 1)
            charStack.pop_back();

        string result(charStack.begin(), charStack.end());
        return result;
    }

private:
    vector<char> charStack;
};
