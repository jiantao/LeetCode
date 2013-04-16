/*
 * =====================================================================================
 *
 *       Filename:  text_justification.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2013 06:25:09 PM
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
    vector<string> fullJustify(vector<string> &words, int L) 
    {
        results.clear();
        temp.clear();

        int size = words.size();
        int cumLen = 0;

        for (int i = 0; i != size; ++i)
        {
            if (cumLen == 0)
            {
                temp.push_back(words[i]);
                cumLen += words[i].length();
            }
            else
            {
                if (cumLen + (int) words[i].length() + 1 <= L)
                {
                    temp.push_back(words[i]);
                    cumLen += words[i].length() + 1;
                }
                else
                {
                    string formatted("");
                    formatString(formatted, cumLen, L);
                    results.push_back(formatted);

                    temp.clear();
                    temp.push_back(words[i]);
                    cumLen = words[i].length();
                }
            }
        }

        string formatted(temp[0]);
        int left = temp.size() - 1;
        for (int i = 0; i != left; ++i)
            formatted += " " + temp[i+1];

        formatted += string(L - cumLen, ' ');
        results.push_back(formatted);

        return results;
    }

private:
    void formatString(string& formatted, int cumLen, int L)
    {
        formatted += temp[0];
        int left = L - cumLen;

        int size = temp.size();
        if (size > 1)
        {
            int avg = left / (size - 1) + 1;
            int remaining = left % (size - 1);

            string first(avg, ' ');
            string second(avg + 1, ' ');
            
            for (int i = 0; i != remaining; ++i)
                formatted += second + temp[1 + i];

            for (int i = 0; i < size - remaining - 1; ++i)
                formatted += first + temp[remaining + i + 1];
        }
        else
            formatted += string(left, ' ');
    }

private:
    vector<string> results;
    vector<string> temp;
};

int main(int argc, char *argv[])
{
    vector<string> words;
    words.push_back(string("a"));
    words.push_back(string("b"));
    words.push_back(string("cde"));
    words.push_back(string("d"));
    words.push_back(string("e"));

    Solution solution;
    vector<string> results = solution.fullJustify(words, 4);

    for (unsigned i = 0; i != results.size(); ++i)
        cout << results[i] << "|" << endl;

    return 0;
}
