/*
 * =====================================================================================
 *
 *       Filename:  convert_list_to_bst.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 12:32:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) 
    {
        listIter = head;
        ListNode* end = NULL;
        int size = 0;

        for (end = head; end != NULL; end = end->next)
            ++size;

        return medOrder(0, size - 1);
    }

private:

    TreeNode* medOrder(int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode* left = medOrder(start, mid - 1);

        TreeNode* root = new TreeNode(listIter->val);
        root->left = left;

        listIter = listIter->next;
        root->right = medOrder(mid + 1, end);

        return root;
    }

private:
    ListNode* listIter;
};
