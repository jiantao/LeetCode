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

class Solution2
{
public:
    vector<string> generateParenthesis(int n) 
    {
        result.clear();
        if (n == 0)
            return result;

        temp.resize(2 * n);
        doGenerate(0, 0, n);
        return result;
    }

private:
    void doGenerate(int left, int right, int n)
    {
        if (left == n && right == n)
        {
            result.push_back(temp);
            return;
        }

        if (left != n)
        {
            temp[left + right] = '(';
            doGenerate(left+1, right, n);
        }

        if (left > right)
        {
            temp[left+right] = ')';
            doGenerate(left, right+1, n);
        }
    }

private:
    vector<string> result;
    string temp;
};

int main(int argc, char *argv[])
{
    Solution solution;

    vector<string> result = solution.generateParenthesis(4);
    
    for (unsigned i = 0; i != result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
