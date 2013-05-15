/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/15/13 16:39:02
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
    void mergeSort(vector<int>& nums)
    {
        int n = nums.size();
        temp.resize(n);

        doMergeSort(nums, 0, n-1);
    }

private:
    void doMergeSort(vector<int>& nums, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        doMergeSort(nums, low, mid);
        doMergeSort(nums, mid+1, high);

        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high)
    {
        int lIter = low;
        int hIter = mid + 1;
        int tIter = low;
        while (lIter <= mid && hIter <= high)
        {
            if (nums[lIter] < nums[hIter])
            {
                temp[tIter] = nums[lIter];
                ++lIter;
            }
            else
            {
                temp[tIter] = nums[hIter];
                ++hIter;
            }

            ++tIter;
        }

        // low part is merged and move the rest of high part
        // into the sorted array
        if (lIter > mid)
        {
            while (hIter <= high)
            {
                temp[tIter] = nums[hIter];
                ++tIter;
                ++hIter;
            }
        }
        else
        {
            while (lIter <= mid)
            {
                temp[tIter] = nums[lIter];
                ++lIter;
                ++tIter;
            }
        }

        for (int i = low; i <= high; ++i)
            nums[i] = temp[i];
    }

private:
    vector<int> temp;
};


int main(int argc, char *argv[])
{
    vector<int> input;

    for (int i = 99; i >= 0; --i)
        input.push_back(i);

    for (int i = 0; i != 100; ++i)
        cout << input[i] << endl;

    cout << endl;
    Solution solution;
    solution.mergeSort(input);

    for (int i = 0; i != 100; ++i)
        cout << input[i] << endl;

    return 0;
}
