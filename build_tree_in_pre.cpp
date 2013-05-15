/*
 * =====================================================================================
 *
 *       Filename:  build_tree_in_pre.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/15/13 17:13:07
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
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
        int n = preorder.size();
        if (n == 0)
            return NULL;

        return doBuildTree(preorder, 0, n - 1, inorder, 0, n - 1);
    }

private:
    TreeNode* doBuildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int idx = inStart;
        for (; idx <= inEnd; ++idx)
        {
            if (inorder[idx] == preorder[preStart])
                break;
        }

        int preLeftEnd = preStart + idx - inStart;
        TreeNode* leftTree = doBuildTree(preorder, preStart + 1, preLeftEnd, inorder, inStart, idx - 1);
        TreeNode* rightTree = doBuildTree(preorder, preLeftEnd + 1, preEnd, inorder, idx + 1, inEnd);

        root->left = leftTree;
        root->right = rightTree;

        return root;
    }
};
