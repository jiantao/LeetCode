/*
 * =====================================================================================
 *
 *       Filename:  generate_parentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 11:50:58 PM
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
    vector<string> generateParenthesis(int n) 
    {
        temp.clear();
        result.clear();

        doGenerate(n, n);

        return result;
    }

private:
    void doGenerate(int left, int right)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(temp);
            return;
        }

        if (left == right)
        {
            temp.push_back('(');
            doGenerate(left - 1,  right);
            temp.erase(temp.size() - 1);
        }
        else if (left < right) 
        {
            if (left != 0)
            {
                temp.push_back('(');
                doGenerate(left - 1,  right);
                temp.erase(temp.size() - 1);
            }

            temp.push_back(')');
            doGenerate(left,  right - 1);
            temp.erase(temp.size() - 1);
        }
    }

private:
    string temp;
    vector<string> result;
};

int main(int argc, char *argv[])
{
    Solution solution;

    vector<string> result = solution.generateParenthesis(4);
    
    for (unsigned i = 0; i != result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
