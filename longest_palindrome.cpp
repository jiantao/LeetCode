/*
 * =====================================================================================
 *
 *       Filename:  longest_palindrome.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/11/2013 12:19:57 AM
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
    int longestPalindrome(const string& str)
    {
        int len = str.length();
        vector<vector<bool>> table(len);

        for (int i = 0; i != len; ++i)
            table[i].resize(len, false);

        int longest = 0;
        for (int j = 0; j != len; ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                if ((j - i < 3 || table[i+1][j-1]) && str[i] == str[j])
                {
                    table[i][j] = true;
                    int currLen = j - i + 1;
                    if (currLen > longest)
                        longest = currLen;
                }
            }
        }

        return longest;
    }
};

class Solution2
{
public:
    string longestPalindrome(const string& str)
    {
        int len = str.length();
        int longest = 0;
        int start = 0;

        for (int i = 0; i != len; ++i)
        {
            int left = i;
            int right = i;
            expandAroundCenter(str, left, right);
            if (right - left + 1 > longest)
            {
                longest = right - left + 1;
                start = left;
            }

            left = i;
            right = i + 1;
            expandAroundCenter(str, left, right);
            if (right - left + 1 > longest)
            {
                longest = right - left + 1;
                start = left;
            }
        }

        string result = str.substr(start, longest);
        return result;
    }
    
private:
    void expandAroundCenter(const string& s, int& c1, int& c2)
    {
        int len = s.length();
        while (c1 >= 0 && c2 <= len - 1 && s[c1] == s[c2])
        {
            --c1;
            ++c2;
        }

        ++c1;
        --c2;
    }
};

int main(int argc, char *argv[])
{
    string str = "abbbbbbbaccddddddddddcc";
    Solution2 solution;
    cout << solution.longestPalindrome(str) << endl;
    return 0;
}
