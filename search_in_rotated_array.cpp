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
    int search(int A[], int n, int target) 
    {
        if (n == 0)
            return -1;

        int rtIdx = findRotatePoint(A, 0, n - 1);
        if (rtIdx < 0)
            return binarySearch(A, target, 0, n - 1);
        else
        {
            int idx = binarySearch(A, target, 0, rtIdx);
            if (idx >= 0)
                return idx;

            idx = binarySearch(A, target, rtIdx + 1, n - 1);
            return idx;
        }
    }

    int findRotatePoint(int array[], int low, int high)
    {
        if (high <= low)
            return -1;

        if (low + 1 == high)
        {
            if (array[low] > array[high])
                return low;
            else 
                return -1;
        }

        int mid = (low + high) / 2;
        if (array[mid] >= array[low] && array[mid] <= array[high])
            return -1;
        else if (array[mid] < array[low])
            return findRotatePoint(array, low, mid);
        else
            return findRotatePoint(array, mid, high);
    }

    int binarySearch(int array[], int target, int low, int high)
    {
        if (high < low)
            return -1;

        int mid = (low + high) / 2;
        if (array[mid] == target)
            return mid;
        else if (array[mid] > target)
            return binarySearch(array, target, low, mid - 1);
        else 
            return binarySearch(array, target, mid + 1, high);
    }
};

class Solution2
{
public:
    int search(int A[], int n, int target) 
    {
        return doSearch(A, 0, n - 1, target);
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
    int array[] = {3, 1};

    Solution solution;
    int idx = solution.findRotatePoint(array, 0, 1);

    cout << idx << endl;

    return 0;
}
