/*
 * =====================================================================================
 *
 *       Filename:  find_all_substrings.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 12:14:09 AM
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
    vector<int> findSubstring(string S, vector<string> &L) 
    {
        result.clear();
        hash.clear();

        int size = L.size();
        if (size == 0)
            return result;

        int wLen = L[0].length();
        int sLen = S.length();
        if (sLen == 0)
            return result;

        for (int i = 0; i != size; ++i)
        {
            ++hash[L[i]];
        }

        int limit = wLen * size;
        for (int i = 0 ; i <= sLen - limit; ++i)
        {
            if (isFound(S, i, wLen, size))
                result.push_back(i);
        }

        return result;
    }

private:
    bool isFound(const string& str, int pos, int wLen, int size)
    {
        unordered_map<string, int> temp(hash);
        string word;
        int count = size;
        for (int i = pos; i != pos + wLen * size; i += wLen)
        {
            word.assign(str.begin() + i, str.begin() + i + wLen);
            if (temp[word] > 0)
            {

                --temp[word];
                --count;
            }
            else
                return false;
        }

        if (count == 0)
            return true;
        else
            return false;
    }

private:
    vector<int> result;
    unordered_map<string, int> hash;
};

int main(int argc, char *argv[])
{
    string str = "foobarthebarfooman";
    vector<string> words(2, "foo");
    words[1] = "bar";

    Solution solution;
    vector<int> result = solution.findSubstring(str, words);

    for (unsigned i = 0; i != result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
