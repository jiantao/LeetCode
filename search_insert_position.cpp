/*
 * =====================================================================================
 *
 *       Filename:  search_insert_position.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/01/2013 10:10:32 PM
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
    int searchInsert(int A[], int n, int target) 
    {
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (target == A[mid])
                return mid;
            else if (target > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

int main(int argc, char *argv[])
{
    int test[] = {1, 3, 5, 6};
    Solution solution;
    cout << solution.searchInsert(test, 4, 0) << endl;
    return 0;
}
