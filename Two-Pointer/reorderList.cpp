#include <iostream>

using namespace std;

// https://leetcode.com/problems/reorder-list/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head)
{
    if (!head || !(head->next))
        return head;

    ListNode *temp = head->next;
    ListNode *ahead = temp->next;
    ListNode *prev = head;

    prev->next = nullptr;

    while (temp && temp->next)
    {
        temp->next = prev;
        prev = temp;
        temp = ahead;
        if (ahead)
            ahead = ahead->next;
    }
    if (temp)
        temp->next = prev;

    return temp;
}

void merge(ListNode *head1, ListNode *head2)
{
    if (!head1 || !head2)
        return;

    ListNode *temp1 = head1;
    ListNode *ahead1 = head1->next;
    ListNode *temp2 = head2;
    ListNode *ahead2 = head2->next;

    bool chance = true;

    while (temp1 && temp2)
    {
        if (chance)
        {
            temp1->next = temp2;
            temp1 = ahead1;
            if (ahead1)
                ahead1 = ahead1->next;
        }
        else
        {
            temp2->next = temp1;
            temp2 = ahead2;
            if (ahead2)
                ahead2 = ahead2->next;
        }
        chance = !chance;
    }
}

void reorderList(ListNode *head)
{
    if (!head || !(head->next))
        return;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse from slow -> next to end
    ListNode *l2 = reverse(slow);
    prev->next = nullptr;

    merge(head, l2);
}
