/*
 * =====================================================================================
 *
 *       Filename:  merge_sorted_lists.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2013 01:00:59 AM
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
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;

        ListNode* head = NULL;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;

        if (iter1->val < iter2->val)
        {
            head = l1;
            iter1 = iter1->next;
        }
        else
        {
            head = l2;
            iter2 = iter2->next;
        }

        ListNode* last = head;
        while (iter1 != NULL && iter2 != NULL)
        {
            if (iter1->val < iter2->val)
            {
                last->next = iter1;
                iter1 = iter1->next;
            }
            else
            {
                last->next = iter2;
                iter2 = iter2->next;
            }

            last = last->next;
        }

        if (iter1 == NULL)
            last->next = iter2;
        else
            last->next = iter1;

        return head;
    }
};
