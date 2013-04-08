/*
 * =====================================================================================
 *
 *       Filename:  inorder_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2013 05:20:38 PM
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
    vector<int> inorderTraversal(TreeNode *root) 
    {
        vector<int> results;
        if (root == NULL)
            return results;

        vector<TreeNode*> nodeStack;
        vector<int> visitStack;

        nodeStack.push_back(root);
        visitStack.push_back(0);

        while (nodeStack.size() > 0)
        {
            TreeNode* current = nodeStack.back();
            int visit = visitStack.back();
            ++(visitStack.back());

            if (visit == 0)
            {
                if (current->left != NULL)
                {
                    nodeStack.push_back(current->left);
                    visitStack.push_back(0);
                }
            }
            else if (visit == 1)
                results.push_back(current->val);
            else
            {
                nodeStack.pop_back();
                visitStack.pop_back();
                if (current->right != NULL)
                {
                    nodeStack.push_back(current->right);
                    visitStack.push_back(0);
                }
            }
        }

        return results;
    }
};
