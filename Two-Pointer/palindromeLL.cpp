#include <iostream>

using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/description/?envType=problem-list-v2&envId=two-pointers

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
    ListNode *prev = head;
    ListNode *temp = head->next;
    ListNode *ahead = temp->next;

    while (temp)
    {
        temp->next = prev;
        prev = temp;
        temp = ahead;
        if (ahead)
            ahead = ahead->next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (!head || !(head->next))
        return true;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    ListNode *head2 = reverse(slow);

    ListNode *temp1 = head;
    ListNode *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->val != temp2->val)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
