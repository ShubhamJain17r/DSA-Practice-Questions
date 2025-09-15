#include <iostream>

using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head || !(head->next))
        return nullptr;

    ListNode *curr = head;
    ListNode *end = nullptr;

    int count = 0;

    while (curr->next)
    {
        count++;
        if (end)
            end = end->next;

        if (count == n)
        {
            end = head;
        }

        curr = curr->next;
    }
    if (end == nullptr)
        return head->next;
    end->next = end->next->next;
    return head;
}