/*
 * =====================================================================================
 *
 *       Filename:  max_depth_of_binary_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2013 03:13:25 PM
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
    int maxDepth(TreeNode *root) 
    {
        return findMax(root);
    }

private:
    int findMax(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int leftHigh = findMax(root->left);
        int righttHigh = findMax(root->right);

        return leftHigh > righttHigh ? leftHigh + 1 : righttHigh + 1;
    }
};
