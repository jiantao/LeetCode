/*
 * =====================================================================================
 *
 *       Filename:  connect_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/2013 11:24:40 PM
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
#include <limits.h>

using namespace std;


struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:

    void connect(TreeLinkNode *root) 
    {
        if (root == NULL)
            return;

        root->next = NULL;
        TreeLinkNode* lastLevel = root;
        TreeLinkNode* currLevel = NULL;
        TreeLinkNode* currHead = NULL;
        while (lastLevel != NULL)
        {
            TreeLinkNode* left = lastLevel->left;
            TreeLinkNode* right = lastLevel->right;

            if (left != NULL)
            {
                if (currHead != NULL)
                {
                    currLevel->next = left;
                    currLevel = left;
                }
                else
                {
                    currHead = left;
                    currLevel = left;
                }
            }

            if (right != NULL)
            {
                if (currHead != NULL)
                {
                    currLevel->next = right;
                    currLevel = right;
                }
                else
                {
                    currHead = right;
                    currLevel = right;
                }
            }

            if (currLevel != NULL)
                currLevel->next = NULL;

            lastLevel = lastLevel->next;
            if (lastLevel == NULL)
            {
                lastLevel = currHead;
                currHead = NULL;
                currLevel = NULL;
            }
        }
    }
};
