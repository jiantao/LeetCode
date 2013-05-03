/*
 * =====================================================================================
 *
 *       Filename:  search_for_range.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/01/2013 10:39:56 PM
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
    vector<int> searchRange(int A[], int n, int target) 
    {
        result.resize(2, -1);

        int low = 0; 
        int high = n - 1;

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (target <= A[mid])
                high = mid;
            else
                low = mid + 1;
        }

        if (target == A[low])
            result[0] = low;
        else
            return result;

        low = 0; 
        high = n - 1;

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (target < A[mid])
                high = mid;
            else
                low = mid + 1;
        }

        if (A[low] == target)
            result[1] = low;
        else if (A[low - 1] == target)
            result[1] = low - 1;

        return result;
    }

private:
    vector<int> result;
};


int main(int argc, char *argv[])
{
    int test[] = {1, 5};
    Solution solution;

    vector<int> result = solution.searchRange(test, 2, 4);

    cout << result[0] << "\t" << result[1] << endl;
    return 0;
}
