/*
 * =====================================================================================
 *
 *       Filename:  merge_k_lists.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 11:03:29 PM
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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct CompareListNode
{
    bool operator () (const ListNode* a, const ListNode* b)
    {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        ListNode* head = NULL;
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> nodeQueue;

        for (unsigned i = 0 ; i != lists.size(); ++i)
        {
            if (lists[i] != NULL)
                nodeQueue.push(lists[i]);
        }

        ListNode* iter = head;
        while (!nodeQueue.empty())
        {
            ListNode* curr = nodeQueue.top();
            if (iter != NULL)
                iter->next = curr;
            else
                head = curr;

            iter = curr;

            if (curr->next != NULL)
                nodeQueue.push(curr->next);

            nodeQueue.pop();
        }

        return head;
    }
};
