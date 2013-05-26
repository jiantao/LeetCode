/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_level_order_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2013 09:00:37 PM
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
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        temp.clear();
        result.clear();
        nodeQue.clear();
        levelQue.clear();

        if (root == NULL)
            return result;

        nodeQue.push_back(root);
        levelQue.push_back(1);
        int lastLevel = 1;
        while (!nodeQue.empty())
        {
            int currLevel = levelQue.front();
            TreeNode* currNode = nodeQue.front();

            if (currNode->left != NULL)
            {
                nodeQue.push_back(currNode->left);
                levelQue.push_back(currLevel + 1);
            }

            if (currNode->right != NULL)
            {
                nodeQue.push_back(currNode->right);
                levelQue.push_back(currLevel + 1);
            }

            if (currLevel != lastLevel)
            {
                result.push_back(temp);
                temp.clear();
                lastLevel = currLevel;
            }

            temp.push_back(currNode->val);
            nodeQue.pop_front();
            levelQue.pop_front();
        }

        result.push_back(temp);
        return result;
    }

private:
    deque<TreeNode*> nodeQue;
    deque<int> levelQue;
    vector<vector<int>> result;
    vector<int> temp;
};
