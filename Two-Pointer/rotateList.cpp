#include <iostream>

using namespace std;

// https://leetcode.com/problems/rotate-list/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (k == 0 || !head || !(head->next))
        return head;
    int len = 1;
    ListNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
        len++;
    }
    k %= len;
    if (!k)
        return head;
    ListNode *prev = nullptr;

    temp = head;
    while (temp->next)
    {
        if (prev)
            prev = prev->next;
        if (k == 1)
        {
            prev = head;
        }
        k--;
        temp = temp->next;
    }
    temp->next = head;
    head = prev->next;
    prev->next = nullptr;
    return head;
}