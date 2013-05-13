/*
 * =====================================================================================
 *
 *       Filename:  max_path_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2013 11:06:12 PM
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:

    int dfs(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int currMax = root->val;
        if (left > 0)
            currMax += left;

        if (right > 0)
            currMax += right;

        if (maxSum < currMax)
            maxSum = currMax;

        if (left < 0 && right < 0)
            return root->val;
        else
        {
            if (left > right)
                return (root->val + left);
            else
                return (root->val + right);
        }
    }

    int maxPathSum(TreeNode *root) 
    {
        maxSum = INT_MIN;
        dfs(root);

        return maxSum;
    }

private:
    int maxSum;
};

class SolutionDup
{
public:

    int maxPathSum(TreeNode *root) 
    {
        maxSum = INT_MIN;
        postOrder(root);

        return maxSum;
    }

    int postOrder(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int leftSum = postOrder(root->left);
        int rightSum = postOrder(root->right);

        int currMax = root->val;
        if (leftSum > 0)
            currMax += leftSum;
        
        if (rightSum > 0)
            currMax += rightSum;

        if (currMax > maxSum)
            maxSum = currMax;

        if (leftSum < 0 && rightSum < 0)
            return currMax;
        else
        {
            if (leftSum > rightSum)
                return (root->val + leftSum);
            else
                return (root->val + rightSum);
        }
    }

private:
    int maxSum;
};
