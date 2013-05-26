/*
 * =====================================================================================
 *
 *       Filename:  reverse_k_group.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2013 06:26:29 PM
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
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        ListNode* newHead = head;
        ListNode* begin = head;
        ListNode* end = head;
        ListNode* prev = NULL;

        while (begin != NULL)
        {
            int count = 1;
            while (end != NULL && count != k)
            {
                ++count;
                end = end->next;
            }
            
            if (end == NULL)
                break;

            ListNode* after = end->next;
            reverseK(begin, end);

            if (prev == NULL)
                newHead = begin;
            else
                prev->next = begin;

            prev = end;

            end->next = after;
            begin = after;
            end = begin;
        }

        return newHead;
    }

private:
    void reverseK(ListNode*& begin, ListNode*& end)
    {
        ListNode* newEnd = begin;
        ListNode* newBegin = end;

        ListNode* iter = begin;
        while (iter != end)
        {
            ListNode* next = iter->next;
            iter->next = newBegin->next;
            newBegin->next = iter;
            iter = next;
        }

        begin = newBegin;
        end = newEnd;
    }
};

int main(int argc, char *argv[])
{
    ListNode* head = new ListNode(1);

    ListNode* end = head;
    for (int i = 2; i != 6; ++i)
    {
        ListNode* newNode = new ListNode(i);
        end->next = newNode;
        end = newNode;
    }
    end->next = NULL;

    ListNode* iter = head;
    while (iter != NULL)
    {
        cout << iter->val << "->";
        iter = iter->next;
    }
    cout << endl;

    Solution solution;
    ListNode* newHead = solution.reverseKGroup(head, 2);

    iter = newHead;
    while (iter != NULL)
    {
        cout << iter->val << "->";
        iter = iter->next;
    }
    cout << endl;

    return 0; 
}
