/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/2013 09:44:34 PM
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

class Solution {
public:
    int firstMissingPositive(int A[], int n) 
    {
        for (int i = 0; i != n ; ++i)
        {
            while (A[i] != i + 1)
            {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;

                swap(A[i], A[A[i] - 1]);
            }
        }

        for (int i = 0; i != n; ++i)
        {
            if (A[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

int main(int argc, char *argv[])
{
    int test[] = {1, -1, 4, 1000};
    Solution solution;

    int result = solution.firstMissingPositive(test, 4);
    cout << result << endl;
    return 0;
}
