/*
 * =====================================================================================
 *
 *       Filename:  recover_bst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2013 12:06:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <limits.h>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) 
    {
        last = NULL;
        first = NULL;
        firstPost = NULL;
        second = NULL;

        inorder(root);

        TreeNode* which = second == NULL ? firstPost : second;
        int temp = first->val;
        first->val = which->val;
        which->val = temp;
    }

private:
    void inorder(TreeNode* curr)
    {
        if (curr == NULL)
            return;

        if (first != NULL && second != NULL)
            return;

        inorder(curr->left);
        if (last != NULL)
        {
            if (curr->val < last->val)
            {
                if (first == NULL)
                {
                    first = last;
                    firstPost = curr;
                }
                else if (second == NULL)
                    second = curr;
            }
        }

        last = curr;
        inorder(curr->right);
    }

private:
    
    TreeNode* last;
    TreeNode* first;
    TreeNode* firstPost;
    TreeNode* second;
};
