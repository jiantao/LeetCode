/*
 * =====================================================================================
 *
 *       Filename:  distinct_subsequences.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2013 01:18:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

class Solution 
{
public:
    int numDistinct(string S, string T) 
    {
        return countDistinct(S, T);
    }

private:
    int countDistinct(const string& S, const string& T)
    {
        if (T.empty())
            return 1;

        if (S.empty())
            return 0;

        if (S[0] == T[0])
            return countDistinct(S.substr(1), T.substr(1)) + countDistinct(S.substr(1), T);
        else
            return countDistinct(S.substr(1), T);
    }
};

class Solution_1
{
public:
    int numDistinct(string S, string T) 
    {
        int sLen = S.size();
        int tLen = T.size();

        if (tLen == 0)
            return 1;

        if (sLen == 0)
            return 0;

        vector<int> count(tLen + 1, 0);
        count[0] = 1;

        for (int i = 1; i <= sLen; ++i)
        {
            for (int j = tLen; j > 0; --j)
            {
                if (S[i - 1] == T[j - 1])
                    count[j] += count[j - 1];
            }
        }

        return count[tLen];
    }
};


int main(int argc, char *argv[])
{
    string test("x");
    try
    {
        string s = test.substr(1);
        if (s.empty())
            cout << "Empty string" << "\n";
    }
    catch (const std::out_of_range& oor)
    {
        cerr << "ERROR: Out of range: " << oor.what() << "\n";
        exit(1);
    }

    return 0;
}
