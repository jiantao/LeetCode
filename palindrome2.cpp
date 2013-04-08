/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2013 08:50:46 PM
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
#include <iostream>

using namespace std;


class Solution
{
    public:
        int minCut(string str)
        {
            int strLen = str.size();
            if (strLen == 0)
                return 0;

            // find the minimum cut if cut before i
            vector<int> numCut(strLen + 1);
            for (int i = 0; i != strLen + 1; ++i)
                numCut[i] = strLen - i;

            vector<int> traceBack(strLen);
            for (int i = 0; i != strLen; ++i)
                traceBack[i] = i + 1;

            // dynamic programming to check if a 
            // string is palindrome
            vector<vector<bool> > pos;
            pos.resize(strLen);
            for (int i = 0; i != strLen; ++i)
                pos[i].resize(strLen, false);

            for (int i = strLen - 1; i >= 0; --i)
            {
                int min = numCut[i];
                for (int j = i; j < strLen; ++j)
                {
                    if (((j - i < 3) || pos[i + 1][j - 1]) && str[i] == str[j])
                    {
                        pos[i][j] = true;
                        if (min > numCut[j + 1] + 1)
                        {
                            min = numCut[j + 1] + 1;
                            traceBack[i] = j + 1;
                        }
                    }
                }

                numCut[i] = min;
            }

            int j = 0;
            cout << str[0];
            for (int i = 1; i != strLen; ++i)
            {
                if (traceBack[j] == i)
                {
                    cout << "|";
                    j = i;
                }

                cout << str[i];
            }

            cout << endl;

            return numCut[0] - 1;
        }
};

int main(int argc, char *argv[])
{
    string str(argv[1]);
    Solution solution;
    cout << solution.minCut(str) << endl;

    return 0;
}
