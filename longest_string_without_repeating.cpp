/*
 * =====================================================================================
 *
 *       Filename:  longest_string_without_repeating.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/18/2013 10:17:26 PM
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
    int lengthOfLongestSubstring(string s) 
    {  
        hash.clear();
        int max = 0;
        int len = s.length();

        int start = 0;
        int currLen = 0;
        for (int i = 0; i != len; ++i)
        {
            unordered_map<char, int>::iterator iter;
            iter = hash.find(s[i]);
            if (iter == hash.end())
            {
                hash[s[i]] = i;
                ++currLen;
                if (currLen > max)
                    max = currLen;
            }
            else
            {
                int end = iter->second;
                currLen -= end - start;

                for (int j = start; j <= end; ++j)
                    hash.erase(s[j]);

                hash[s[i]] = i;
                start = end + 1;
            }
        }

        return max;
    }

private:
    unordered_map<char, int> hash;
};

int main(int argc, char *argv[])
{
    string test("abcabcde");
    Solution solution;

    cout << solution.lengthOfLongestSubstring(test) << endl;

    return 0;
}
