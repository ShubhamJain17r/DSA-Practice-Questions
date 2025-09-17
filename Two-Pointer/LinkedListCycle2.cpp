#include <iostream>

using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (!head || !(head->next))
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    bool isCycle = false;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
        return nullptr;

    fast = head;

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
