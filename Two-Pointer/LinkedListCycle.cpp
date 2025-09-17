#include <iostream>

using namespace std;

// https://leetcode.com/problems/linked-list-cycle/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    // if (!head || !(head -> next)) return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}
