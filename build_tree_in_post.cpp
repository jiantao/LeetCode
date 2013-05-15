/*
 * =====================================================================================
 *
 *       Filename:  build_tree_in_post.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 05:24:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <vector>
#include <unordered_map>
#include <iostream>

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        int size = inorder.size();
        if (size == 0)
            return NULL;

        inorderMap.clear();

        for (int i = 0; i != size; ++i)
            inorderMap[inorder[i]] = i;

        return buildTreeRecursive(inorder, postorder, 0, size - 1, 0, size - 1);
    }

private:

    TreeNode* buildTreeRecursive(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd)
    {
        if (inBegin > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        unordered_map<int, int>::const_iterator rootIter =  inorderMap.find(postorder[postEnd]);

        int rootInPos = rootIter->second;
        int leftSize = rootInPos - inBegin;
        int rightSize = inEnd - rootInPos;

        root->left = buildTreeRecursive(inorder, postorder, inBegin, rootInPos - 1, postBegin, postBegin + leftSize - 1);
        root->right = buildTreeRecursive(inorder, postorder, rootInPos + 1, inEnd, postEnd - rightSize, postEnd - 1);

        return root;
    }

private:
    unordered_map<int, int> inorderMap;
};





























class SolutionDup
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        inorderMap.clear();
        int n = inorder.size();

        for (int i = 0 ; i != n; ++i)
            inorderMap[inorder[i]] = i;

        return doBuildTree(inorder, 0, n - 1, postorder, 0, n - 1);
    }

private:

    TreeNode* doBuildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd)
            return NULL;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderMap[rootVal];

        int leftPostEnd = postStart + idx - inStart - 1;
        TreeNode* leftTree = doBuildTree(inorder, inStart, idx - 1, postorder, postStart, leftPostEnd);
        TreeNode* rightTree = doBuildTree(inorder, idx + 1, inEnd, postorder, leftPostEnd + 1, postEnd - 1);

        root->left = leftTree;
        root->right = rightTree;

        return root;
    }

private:
    unordered_map<int, int> inorderMap;
};
