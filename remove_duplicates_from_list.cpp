/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/2013 08:59:08 PM
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
        ListNode* curr = head;
        ListNode* prevDup = NULL;

        bool isStart = false;

        while (curr != NULL)
        {
            ListNode* next = curr->next;
            if (next != NULL && curr->val == next->val)
            {
                if (!isStart)
                {
                    prevDup = curr;
                    isStart = true;
                }

                curr = curr->next;
            }
            else if (next == NULL || curr->val != next->val)
            {
                if (isStart)
                {
                    curr = CleanUp(prevDup, curr);
                    isStart = false;
                }
                else
                    curr = curr->next;
            }
        }

        return head;
    }

private:

    ListNode* CleanUp(ListNode* prevDup, ListNode* dupTail)
    {
        ListNode* ret = dupTail->next;
        ListNode* dupHead = prevDup->next;

        prevDup->next = dupTail->next;
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
