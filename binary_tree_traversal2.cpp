/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_traversal2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 04:41:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits.h>

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;

        levelNodes.clear();
        nodeQue.clear();
        levelQue.clear();

        int lastLevel = 0;
        nodeQue.push_back(root);
        levelQue.push_back(0);

        while (nodeQue.size() > 0)
        {
            TreeNode* currNode = nodeQue.front();
            int currLevel = levelQue.front();

            if (currLevel != lastLevel)
            {
                ret.push_back(levelNodes);
                levelNodes.clear();
            }

            lastLevel = currLevel;
            levelNodes.push_back(currNode->val);

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

            nodeQue.pop_front();
            levelQue.pop_front();
        }

        ret.push_back(levelNodes);
        reverse(ret.begin(), ret.end());

        return ret;
    }

private:
    vector<int> levelNodes;
    deque<TreeNode*> nodeQue;
    deque<int> levelQue;
};
