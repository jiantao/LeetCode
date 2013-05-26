/*
 * =====================================================================================
 *
 *       Filename:  add_two_number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2013 09:17:07 PM
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        int carry = 0;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        ListNode* newHead = NULL;
        ListNode* newIter = NULL;
        while (iter1 != NULL || iter2 != NULL)
        {
            int val1 = iter1 == NULL ? 0 : iter1->val;
            int val2 = iter2 == NULL ? 0 : iter2->val;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            if (newHead == NULL)
            {
                newHead = newNode;
                newIter = newNode;
            }
            else
            {
                newIter->next = newNode;
                newIter = newNode;
            }

            if (iter1 != NULL)
                iter1 = iter1->next;

            if (iter2 != NULL)
                iter2 = iter2->next;
        }

        if (carry > 0)
        {
            ListNode* newNode = new ListNode(carry);
            newIter->next = newNode;
        }

        return newHead;
    }
};
