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
        ListNode* iter1 = head;
        ListNode* iter2 = head;
        int k = n;
        while (iter2 != NULL && k > 0)
        {
            iter2 = iter2->next;
            --k;
        }

        ListNode* prev = NULL;
        while (iter2 != NULL)
        {
            if (prev != NULL)
                prev = prev->next;
            else
                prev = head;

            iter1 = iter1->next;
            iter2 = iter2->next;
        }

        ListNode* newHead = head;
        if (prev != NULL)
            prev->next = iter1->next;
        else
            newHead = iter1->next;

        return newHead;
    }
};
