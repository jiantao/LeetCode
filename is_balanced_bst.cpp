/*
 * =====================================================================================
 *
 *       Filename:  is_balanced_bst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2013 09:47:48 PM
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
    bool isBalanced(TreeNode *root) 
    {
        isBal = true;
        postOder(root);

        return isBal;
    }

private:

    int postOder(TreeNode* root)
    {
        if (!isBal)
            return 0;

        if (root == NULL)
            return 0;

        int left = postOder(root->left);
        int right = postOder(root->right);

        int max = left > right ? left : right;
        if (max - left > 1 || max - right > 1)
            isBal = false;

        return max + 1;
    }

private:

    bool isBal;
};
