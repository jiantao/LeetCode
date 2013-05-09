/*
 * =====================================================================================
 *
 *       Filename:  integer_to_roman.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2013 10:26:00 PM
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
    Solution()
    {
        buildHash();
    }

    string intToRoman(int num) 
    { 
        string result("");
        map<int, char>::reverse_iterator iter;

        int left = num;
        for (iter = hash.rbegin(); iter != hash.rend(); ++iter)
        {
            int remains = left / iter->first;
            for (int i = 0; i != remains; ++i)
                result += iter->second;

            left = left % iter->first;
            map<int, char>::reverse_iterator lessIter = iter;
            if (iter->first == 1000 || iter->first == 100 || iter->first == 10)
            {
                ++lessIter;
                ++lessIter;
            }
            else if (iter->first == 500 || iter->first == 50 || iter->first == 5)
                ++lessIter;
            else
                continue;

            remains = left / (iter->first - lessIter->first);
            for (int i = 0; i != remains; ++i)
            {
                result += lessIter->second;
                result += iter->second;
            }

            left = left % (iter->first - lessIter->first);
        }

        return result;
    }

private:
    void buildHash(void)
    {
        hash.insert(pair<int, char>(1000, 'M'));
        hash.insert(pair<int, char>(500, 'D'));
        hash.insert(pair<int, char>(100, 'C'));
        hash.insert(pair<int, char>(50, 'L'));
        hash.insert(pair<int, char>(10, 'X'));
        hash.insert(pair<int, char>(5, 'V'));
        hash.insert(pair<int, char>(1, 'I'));
    }

private:
    map<int, char> hash;
};

int main(int argc, char *argv[])
{
    Solution solution;
    cout << solution.intToRoman(1904) << endl;
    return 0;
}
