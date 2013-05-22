/*
 * =====================================================================================
 *
 *       Filename:  reverse_words_in_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2013 09:56:04 PM
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
    void reverseWords(string& str)
    {
        int len = str.length();
        reverseLocal(str, 0, len - 1);

        int start = 0;
        int end = 0;

        while (start < len)
        {
            if (str[start] == ' ')
                ++start;
            else
            {
                end = start;
                while (end < len && str[end] != ' ')
                    ++end;

                reverseLocal(str, start, end - 1);
                start = end + 1;
            }
        }
    }

private:
    void reverseLocal(string& str, int start, int end)
    {
        while (start < end)
        {
            swap(str[start], str[end]);
            ++start;
            --end;
        }
    }
};

int main(int argc, char *argv[])
{
    string test(" yxn wjt | ");
    Solution solution;
    solution.reverseWords(test);

    cout << test << endl;
    return 0;
}
