/*
 * =====================================================================================
 *
 *       Filename:  is_same_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 09:48:44 PM
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
#include <utility>

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
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        isSame = true;

        isSameTreeInp(p, q);

        return isSame;
    }

private:

    void isSameTreeInp(TreeNode* p, TreeNode *q)
    {
        if (!isSame)
            return;

        if (p == NULL && q == NULL)
            return;
        else if (p == NULL || q == NULL)
        {
            isSame = false;
            return;
        }
        else if (p->val != q->val)
        {
            isSame = false;
            return;
        }

        isSameTreeInp(p->left, q->left);
        isSameTreeInp(p->right, q->right);
    }

private:
    bool isSame;
};
