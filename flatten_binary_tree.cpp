/*
 * =====================================================================================
 *
 *       Filename:  flatten_binary_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2013 03:25:39 PM
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

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) 
    {
        TreeNode* last = NULL;
        inorder(root, last);

        TreeNode* iter = root;
        while (iter != NULL)
        {
            iter->right = iter->left;
            iter->left = NULL;
            iter = iter->right;
        }
    }

private:

    void inorder(TreeNode* curr, TreeNode*& last)
    {
        if (curr == NULL)
            return;

        if (last == NULL)
            last = curr;
        else
            last->left = curr;

        last = curr;

        inorder(curr->left, last);
        inorder(curr->right, last);
    }
};
