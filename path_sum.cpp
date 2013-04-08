/*
 * =====================================================================================
 *
 *       Filename:  path_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2013 06:35:21 PM
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
#include <cmath>

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        this->sum = sum;
        ret.clear();
        element.clear();

        inoder(root, 0);

        return ret;
    }

private:
    
    void inoder(TreeNode* curr, int lastSum)
    {
        if (curr == NULL)
            return;

        lastSum += curr->val;
        element.push_back(curr->val);
        if (curr->left == NULL && curr->right == NULL)
        {
            if (lastSum == sum)
                ret.push_back(element);
        }

        inoder(curr->left, lastSum);
        inoder(curr->right, lastSum);

        element.pop_back();
    }

private:
    vector<vector<int> > ret;
    vector<int> element;
    int sum;
};
