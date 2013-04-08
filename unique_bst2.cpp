/*
 * =====================================================================================
 *
 *       Filename:  unique_bst2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2013 03:41:48 PM
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
    vector<TreeNode *> generateTrees(int n) 
    {
        vector<TreeNode*> trees;
        doGenerateTrees(trees, 1, n);
        
        return trees;
    }

private:
    void doGenerateTrees(vector<TreeNode*>& trees, int start, int end)
    {
        if (start > end)
        {
            trees.push_back(NULL);
            return;
        }

        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode*> leftTrees;
            vector<TreeNode*> rightTrees;
            doGenerateTrees(leftTrees, start, i - 1);
            doGenerateTrees(rightTrees, i + 1, end);

            int leftSize = leftTrees.size();
            int rightSize = rightTrees.size();
            for (int j = 0; j != leftSize; ++j)
            {
                for (int k = 0; k != rightSize; ++k)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    trees.push_back(root);
                }
            }
        }
    }
};
