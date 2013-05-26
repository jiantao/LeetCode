/*
 * =====================================================================================
 *
 *       Filename:  swap_pairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 09:54:25 PM
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
    ListNode *swapPairs(ListNode *head) 
    {
        return reverseKGroup(head, 2);
    }

    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        if (k == 0)
            return head;

        int size = 0;
        ListNode* iter = head;
        while (iter != NULL)
        {
            ++size;
            iter = iter->next;
        }

        int count = size / k;

        ListNode* prev = NULL;
        ListNode* after = NULL;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* newHead = head;

        while (count != 0)
        {
            for (int i = 1; i != k; ++i)
                end = end->next;

            after = end->next;
            reverseGroup(start, end);

            if (prev != NULL)
                prev->next = start;
            else
                newHead = start;

            end->next = after;

            prev = end;
            start = after;
            end = after;

            --count;
        }

        return newHead;
    }

    void reverseGroup(ListNode*& start, ListNode*& end)
    {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* next = start;

        while (curr != end)
        {
            curr = next;
            next = curr->next;
            curr->next = prev;
            prev = curr;
        }

        ListNode* temp = start;
        start = end;
        end = temp;
    }
};

class Solution2
{
public:
    ListNode *swapPairs(ListNode *head) 
    { 
        ListNode* newHead = head;
        ListNode* iter = head;
        ListNode* prev = NULL;

        while (iter != NULL && iter->next != NULL)
        {
            ListNode* first = iter->next;
            ListNode* after = first->next;

            first->next = iter;
            iter->next = after;

            if (prev == NULL)
                newHead = first;
            else
                prev->next = first;

            prev = iter;
            iter = iter->next;
        }

        return newHead;
    }
};
