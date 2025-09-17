#include <iostream>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = nullptr;

    ListNode *first = nullptr;
    ListNode *temp2 = nullptr;

    while (temp)
    {
        if ((prev && (temp->val == prev->val)) || ((temp->next) && (temp->val == temp->next->val)))
        {
            prev = temp;
            temp = temp->next;
            continue;
        }
        if (!first)
        {
            first = temp;
            temp2 = first;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp2)
        temp2->next = nullptr;

    return first;
}
