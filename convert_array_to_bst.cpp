/*
 * =====================================================================================
 *
 *       Filename:  convert_array_to_bst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 12:45:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        int size = num.size();
        return preOrder(num, 0, size - 1);
    }

private:

    TreeNode* preOrder(const vector<int>& num, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(num[mid]);

        root->left = preOrder(num, start, mid - 1);
        root->right = preOrder(num, mid + 1, end);

        return root;
    }
};
