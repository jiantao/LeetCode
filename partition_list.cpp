/*
 * =====================================================================================
 *
 *       Filename:  partition_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/07/2013 08:56:27 PM
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
    ListNode *partition(ListNode *head, int x) 
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tail = NULL;
        ListNode* ins = NULL;
        ListNode* ret = head;

        while (curr != NULL)
        {
            if (curr->val < x)
            {
                prev = curr;
                curr = curr->next;
            }
            else
                break;
        }

        tail = prev;
        ins = curr;

        while (curr != NULL)
        {
            if (curr->val < x)
            {
                ListNode* next = curr->next;
                if (tail != NULL)
                    tail->next = curr;
                else
                    ret = curr;

                curr->next = ins;
                tail = curr;
                curr = next;
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return ret;
    }
};
