/*
 * =====================================================================================
 *
 *       Filename:  count_and_say.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 11:50:15 AM
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
    string countAndSay(int n) 
    {
        target = "1";
        say = "1";
        for (int i = 0; i != n - 1; ++i)
        {
            int len = target.length();
            char last = target[0];
            int count = 0;
            say.clear();
            for (int j = 0; j != len; ++j)
            {
                if (last == target[j])
                    ++count;
                else
                {
                    say += to_string(count) + last;
                    last = target[j];
                    count = 1;
                }
            }

            say += to_string(count) + last;
            swap(say, target);
        }

        return target;
    }

private:
    string target;
    string say;
};

int main(int argc, char *argv[])
{
    Solution solution;

    string result = solution.countAndSay(5);

    cout << result << endl;
    return 0;
}
