/*
 * =====================================================================================
 *
 *       Filename:  is_valid_bst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/03/2013 10:40:59 PM
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
    bool isValidBST(TreeNode *root) 
    {
        isValid = true;

        int min = INT_MAX;
        int max = INT_MIN;
        postorder(root, min, max);

        return isValid;
    }

private:

    void postorder(TreeNode* root, int& min, int& max)
    {
        if (!isValid)
            return;

        if (root == NULL)
            return;

        int leftMin = INT_MAX;
        int leftMax = INT_MIN;

        int rightMin = INT_MAX;
        int rightMax = INT_MIN;

        postorder(root->left, leftMin, leftMax);
        postorder(root->right, rightMin, rightMax);

        if (leftMax == INT_MIN && rightMin == INT_MAX)
        {
            min = root->val;
            max = root->val;
            return;
        }
        else if (leftMax != INT_MIN && rightMin == INT_MAX)
        {
            if (leftMax > root->val)
            {
                isValid = false;
                return;
            }

            max = root->val;
            min = leftMin;
        }
        else if (rightMin != INT_MAX && leftMax == INT_MIN)
        {
            if (rightMin < root->val)
            {
                isValid = false;
                return;
            }

            max = rightMax;
            min = root->val;
        }
        else
        {
            if (leftMax > root->val || rightMin < root->val)
            {
                isValid = false;
                return;
            }

            max = rightMax;
            min = leftMin;
        }
    }

private:
    
    bool isValid;
};
