/*
 * =====================================================================================
 *
 *       Filename:  min_window_substr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2013 05:46:27 PM
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
    string minWindow(string S, string T) 
    {
        wordInfo.clear();
        headQue.clear();
        preprocess(T);

        int low = INT_MAX;

        int tLen = T.length();
        int sLen = S.length();
        string result("");
        if (tLen == 0 || sLen == 0)
            return result;

        int minLen = INT_MAX;
        int numLeft = tLen;
        unordered_map<char, int>::iterator iter;
        for (int i = 0; i != sLen; ++i)
        {
            iter = wordInfo.find(S[i]);
            if (iter != wordInfo.end())
            {
                if (iter->second > 0)
                    --numLeft;

                --(iter->second);
                headQue.push_back(CharInfo(S[i], i));

                // pop up those redundant characters
                while(wordInfo[headQue.front().c] < 0)
                {
                    ++wordInfo[headQue.front().c];
                    headQue.pop_front();
                }

                if (numLeft == 0)
                {
                    int currLen = headQue.back().i - headQue.front().i + 1;
                    if (currLen < minLen)
                    {
                        minLen = currLen;
                        low = headQue.front().i;
                    }
                }
            }
        }

        if (numLeft == 0)
            result = S.substr(low, minLen);

        return result;
    }

private:

    void preprocess(const string& word)
    {
        int len = word.length();
        for (int i = 0; i != len; ++i)
            ++wordInfo[word[i]];
    }


private:
    struct CharInfo
    {
        char c;
        int i;

        CharInfo(char ch, int idx) : c(ch), i(idx) {};
    };

    unordered_map<char, int> wordInfo;
    deque<CharInfo> headQue;
};
