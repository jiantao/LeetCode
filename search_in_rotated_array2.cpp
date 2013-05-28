/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/2013 10:16:32 PM
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
    bool search(int A[], int n, int target) 
    {
        for (int i = 0; i != n; ++i)
        {
            if (A[i] == target)
                return true;
        }

        return false;
    }
};

class Solution2
{
public:
    bool search(int A[], int n, int target) 
    {
        return doSearch(A, 0, n - 1, target) != -1;
    }

private:
    int doSearch(int A[], int low, int high, int target)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;
        if (A[mid] == target)
            return mid;

        if (A[mid] > A[low]) // left is normal
        {
            if (target >= A[low] && target <= A[mid])
                return doSearch(A, low, mid - 1, target);
            else
                return doSearch(A, mid + 1, high, target);
        }
        else if (A[mid] < A[low])
        {
            if (target >= A[mid] && target <= A[high])
                return doSearch(A, mid + 1, high, target);
            else
                return doSearch(A, low, mid - 1, target);
        }
        else if (A[mid] == A[low])
        {
            if (A[mid] != A[high])
                return doSearch(A, mid + 1, high, target);
            else
            {
                int result = doSearch(A, low, mid - 1, target);
                if (result == -1)
                    return doSearch(A, mid + 1, high, target);
                else
                    return result;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
