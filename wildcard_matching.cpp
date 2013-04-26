/*
 * =====================================================================================
 *
 *       Filename:  wildcard_matching.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/23/2013 11:44:51 PM
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
    bool isMatch(const char *s, const char *p) 
    {
        match = false;
        src = s;
        target = p;

        sLen = strlen(s);
        pLen = strlen(p);

        if (sLen == 0)
        {
            if (pLen != 0)
            {
                int count = pLen;
                for (int i = 0 ; i != pLen; ++i)
                {
                    if (target[i] == '*')
                        --count;
                }

                if (count == 0)
                    return true;
                else
                    return false;
            }
        }

        checkMatch(0, 0);
        return match;
    }

private:
    void checkMatch(int is, int ip)
    {
        if (match)
            return;

        if (is == sLen && ip == pLen)
        {
            match = true;
            return;
        }
        else if (ip == pLen)
            return;
        else if (is == sLen)
        {
            int i = ip;
            while (i != pLen)
            {
                if (target[i] != '*')
                    return;

                ++i;
            }

            match = true;
            return;
        }
        
        switch (target[ip])
        {
            case '*':
                if (ip == pLen - 1)
                {
                    match = true;
                    return;
                }
                else
                    checkMatch(is, ip + 1);
                break;

            case '?':
                if (ip > 0 && target[ip-1] == '*')
                {
                    for (int i = is + 1; i <= sLen; ++i)
                        checkMatch(i, ip + 1);
                }
                else 
                    checkMatch(is + 1, ip + 1);

            default:
                if (ip > 0 && target[ip-1] == '*')
                {
                    for (int i = is; i < sLen; ++i)
                    {
                        if (src[i] == target[ip]) 
                            checkMatch(i+1, ip + 1);
                    }
                }
                else 
                {
                    if (src[is] == target[ip]) 
                        checkMatch(is + 1, ip + 1);
                    else
                        return;
                }

                break;
        }
    }

private:

    const char* src;
    const char* target;

    int sLen;
    int pLen;

    bool match;
};

class Solution2
{
public:
    bool isMatch(const char *s, const char *p) 
    {
        // last '*' position in p
        const char* star = NULL;

        // last match position in s after '*' in p
        const char* ss = NULL;

        while (*s != '\0')
        {
            // if there is a match in s and p move one char in both string
            if ((*p == *s) || (*p == '?')) {++s; ++p; continue;}
            // if there is a '*' in p store the star position in p and match position in s
            if (*p == '*') {ss = s; star = p++; continue;}
            // if there is a mismatch check if there is a '*' appeared before
            // if there is, rematch the substr from the last '*' with ss + 1
            if (star != NULL) {s = ++ss; p = star + 1; continue;}

            return false;
        }

        // if all left chars in p is '*'
        // then it is a match
        while (*p == '*')
                ++p;

        return (*p == '\0');
    }
};

int main(int argc, char *argv[])
{
    string a = "aab";
    string b = "*?*a";

    Solution2 solution;
    if (solution.isMatch(a.c_str(), b.c_str()))
    {
        printf("match\n");
    }

    return 0;
}
