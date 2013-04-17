/*
 * =====================================================================================
 *
 *       Filename:  rotate_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2013 11:55:16 PM
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
    ListNode *rotateRight(ListNode *head, int k) 
    {
        if (head == NULL)
            return head;

        int count = 0;
        ListNode* iter = head;
        ListNode* tail = head;
        while (iter != NULL)
        {
            ++count;
            tail = iter;
            iter = iter->next;
        }

        int remain = k % count;
        if (remain == 0)
            return head;

        iter = head;
        for (int i = 0; i != count - remain - 1; ++i)
            iter = iter->next;

        ListNode* newHead = iter->next;
        iter->next = NULL;
        tail->next = head;

        return newHead;
    }
};
