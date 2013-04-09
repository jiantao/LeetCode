/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_list2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/2013 06:15:55 PM
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
    ListNode *deleteDuplicates(ListNode *head) 
    {
        ListNode* dupHead = head;
        ListNode* curr = head;
        ListNode* newHead = head;
        ListNode* prevDup = NULL;;
        ListNode* prev = NULL;

        bool isStart = false;
        while (curr != NULL)
        {
            ListNode* next = curr->next;
            if (next != NULL)
            {
                if (curr->val == next->val)
                {
                    if (!isStart)
                    {
                        prevDup = prev;
                        dupHead = curr;
                        isStart = true;
                    }

                    prev = curr;
                    curr = curr->next;
                }
                else
                {
                    if (isStart)
                    {
                        prev = prevDup;
                        curr = CleanUp(prevDup, dupHead, curr, newHead);
                        isStart = false;
                    }
                    else
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                }
            }
            else
            {
                if (isStart)
                {
                    prev = prevDup;
                    curr = CleanUp(prevDup, dupHead, curr, newHead);
                    isStart = false;
                }
                else
                    curr = curr->next;
            }
        }

        return newHead;
    }

private:

    ListNode* CleanUp(ListNode* prevDup, ListNode* dupHead, ListNode* dupTail, ListNode*& newHead)
    {
        if (prevDup != NULL)
            prevDup->next = dupTail->next;
        else
            newHead = dupTail->next;

        ListNode* ret = dupTail->next;
        dupTail->next = NULL;

        while (dupHead != NULL)
        {
            ListNode* temp = dupHead;
            dupHead = dupHead->next;
            delete temp;
        }

        return ret;
    }
};
