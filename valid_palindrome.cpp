/*
 * =====================================================================================
 *
 *       Filename:  valid_palindrome.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2013 08:34:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <deque>
#include <set>
#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string cleanedStr(s);
        int strLen = s.length();
        if (strLen == 0)
            return true;

        int pos = 0;
        for (int i = 0; i != strLen; ++i)
        {
            char c = tolower(s[i]);
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                cleanedStr[pos++] = c;
        }

        cleanedStr.resize(pos);
        string reversedStr(cleanedStr.rbegin(), cleanedStr.rend());
        return (cleanedStr == reversedStr);
    }
};

class Solution2
{
public:
    bool isPalindrome(string s) 
    {
        int len = s.length();
        int left = 0;
        int right = len - 1;

        while (left <= right)
        {
            char lChar = tolower(s[left]);
            char rChar = tolower(s[right]);

            if ((lChar < 'a' || lChar > 'z') && (lChar < '0' || lChar > '9'))
                ++left;
            else if ((rChar < 'a' || rChar > 'z') && (rChar < '0' || rChar > '9'))
                --right;
            else
            {
                if (lChar != rChar)
                    return false;

                ++left;
                --right;
            }
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    string test("a, ba");
    Solution2 solution;
    if (solution.isPalindrome(test))
        printf("Is a valid palindrome.\n");
    else
        printf("Is NOT a valid palindrome.\n");

    return 0;
}
