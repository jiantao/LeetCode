/*
 * =====================================================================================
 *
 *       Filename:  min_depth.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2013 09:26:30 PM
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
    int minDepth(TreeNode *root) 
    {
        if (root == NULL)
            return 0;

        nodeQue.clear();
        levelQue.clear();

        nodeQue.push_back(root);
        levelQue.push_back(1);

        while (nodeQue.size() > 0)
        {
            TreeNode* curr = nodeQue.front();
            int level = levelQue.front();

            if (curr->left != NULL)
            {
                nodeQue.push_back(curr->left);
                levelQue.push_back(level + 1);
            }

            if (curr->right != NULL)
            {
                nodeQue.push_back(curr->right);
                levelQue.push_back(level + 1);
            }

            if (curr->left == NULL && curr->right == NULL)
                return level;

            nodeQue.pop_front();
            levelQue.pop_front();
        }
    }

private:

    deque<TreeNode*> nodeQue;
    deque<int> levelQue;
};
