/*
 * =====================================================================================
 *
 *       Filename:  sum_root.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2013 06:48:16 PM
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    struct Vertex
    {
        const TreeNode* node;
        char color;

        Vertex(const TreeNode* otherNode) : node(otherNode), color('w') {};
    };

    int sumNumbers(TreeNode *root) 
    {
        int sum = 0;
        if (root == NULL)
            return sum;

        vector<Vertex> vStack;
        vector<int> num;

        vStack.push_back(Vertex(root));
        num.push_back(root->val);

        while (vStack.size() > 0)
        {
            Vertex& vertex = vStack.back();
            if (vertex.color == 'b')
            { 
                vStack.pop_back();
                num.pop_back();
                continue;
            }

            const TreeNode* node = vertex.node;
            if (node->left != NULL && vertex.color == 'w')
            {
                vertex.color = 'g';
                vStack.push_back(Vertex(node->left));
                num.push_back(node->left->val);
            }
            else
            {
                vertex.color = 'b';
                if (node->right != NULL)
                {
                    vStack.push_back(Vertex(node->right));
                    num.push_back(node->right->val);
                }
                else if (node->left == NULL)
                {
                    int currNum = 0;
                    int size = num.size();
                    for (int i = 0; i != size; ++i)
                        currNum += num[i] * pow(10, size - i - 1);

                    sum += currNum;
                }
            }

        }

        return sum;
    }
};
