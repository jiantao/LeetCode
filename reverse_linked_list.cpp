/*
 * =====================================================================================
 *
 *       Filename:  reverse_linked_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2013 03:15:36 PM
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


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        if (head == NULL)
            return NULL;

        int count = 1;
        ListNode* curr = head;
        prev = NULL;

        while (count != m)
        {
            prev = curr;
            curr = curr->next;
            ++count;
        }

        begin = curr;

        while (count != n)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++count;
        }

        next = curr->next;
        curr->next = prev;
        
        ListNode* newHead = curr;
        if (begin->next != NULL)
        {
            begin->next->next = curr;
            newHead = head;
        }

        begin->next = next;

        return newHead;
    }

private:

    ListNode* begin;
    ListNode* prev;
    ListNode* next;
};

class Solution2
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        int count = 1;
        ListNode* begin = head;
        ListNode* prev = NULL;

        while (count != m)
        {
            ++count;
            prev = begin;
            begin = begin->next;
        }

        ListNode* end = begin;
        while (count != n)
        {
            ++count;
            end = end->next;
        }

        ListNode* after = end->next;

        reverse(begin, end);

        ListNode* newHead = head;
        if (prev == NULL)
            newHead = begin;
        else
            prev->next = begin;

        end->next = after;

        return newHead;
    }

private:
    void reverse(ListNode*& begin, ListNode*& end)
    {
        ListNode* newBegin = end;
        ListNode* iter = begin;

        while (iter != end)
        {
            ListNode* next = iter->next;
            iter->next = newBegin->next;
            newBegin->next = iter;
            iter = next;
        }

        end = begin;
        begin = newBegin;
    }
};
