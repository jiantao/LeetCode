/*
 * =====================================================================================
 *
 *       Filename:  remove_element.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 06:02:52 PM
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
    int removeElement(int A[], int n, int elem) 
    {
        int newLen = n;
        for (int i = 0; i != n; ++i)
        {
            if (i >= newLen)
                break;

            if (A[i] == elem)
            {
                int j = 0;
                for (j = newLen - 1; j > i; --j)
                {
                    if (A[j] != elem)
                    {
                        swap(A[j], A[i]);
                        break;
                    }
                }

                newLen = j;

                if (j == i)
                    return newLen;

            }
        }

        return newLen;
    }
};


int main(int argc, char *argv[])
{
    int test[] = {};
    Solution solution;

    cout << solution.removeElement(test, 0, 1) << endl;
    return 0;
}
