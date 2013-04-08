/*
 * =====================================================================================
 *
 *       Filename:  is_symmetric_bt.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 09:08:36 PM
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
    bool isSymmetric(TreeNode *root) 
    {
        symmetric = true;
        if (root == NULL)
            return symmetric;

        // isSymmetricRecursive(root->left, root->right);
        isSymmetricIterative(root);

        return symmetric;
    }

private:
    void isSymmetricRecursive(TreeNode* leftTree, TreeNode* rightTree)
    {
        if (!symmetric)
            return;

        if (leftTree == NULL && rightTree == NULL)
            return;

        if (leftTree == NULL || rightTree == NULL)
        {
            symmetric = false;
            return;
        }

        if (leftTree->val != rightTree->val)
        {
            symmetric = false;
            return;
        }

        isSymmetricRecursive(leftTree->left, rightTree->right);
        isSymmetricRecursive(leftTree->right, rightTree->left);
    }

    void isSymmetricIterative(TreeNode* root)
    {
        currLevel.clear();
        nextLevel.clear();

        currLevel.push_back(root);
        while (!currLevel.empty() && symmetric)
        {
            TreeNode* currNode = currLevel.front();
            if (currNode != NULL)
            {
                nextLevel.push_back(currNode->left);
                nextLevel.push_back(currNode->right);
            }

            currLevel.pop_front();
            if (currLevel.empty())
            {
                CheckSymmetric();
                swap(currLevel, nextLevel);
            }
        }
    }

    void CheckSymmetric(void)
    {
        for (int i = 0, j = nextLevel.size() - 1; i <= j; ++i, --j)
        {
            if (nextLevel[i] == NULL && nextLevel[j] == NULL)
                continue;
            else if (nextLevel[i] == NULL || nextLevel[j] == NULL)
            {
                symmetric = false;
                break;
            }
            else
            {
                if (nextLevel[i]->val != nextLevel[j]->val)
                {
                    symmetric = false;
                    break;
                }
            }
        }
    }

private:
    bool symmetric;

    deque<TreeNode*> currLevel;
    deque<TreeNode*> nextLevel;
};
