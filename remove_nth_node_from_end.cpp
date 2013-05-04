/*
 * =====================================================================================
 *
 *       Filename:  remove_nth_node_from_end.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 12:47:55 PM
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

class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        helper.clear();
        ListNode* iter = head;
        while (iter != NULL)
        {
            helper.push_back(iter);
            iter = iter->next;
        }

        int idx = helper.size() - n;
        ListNode* newHead = head;
        if (idx != 0)
            helper[idx-1]->next = helper[idx]->next;
        else
            newHead = helper[idx]->next;

        return newHead;
    }

private:
    vector<ListNode*> helper;
};
