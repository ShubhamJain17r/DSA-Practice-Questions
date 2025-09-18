#include <iostream>

using namespace std;

// https://leetcode.com/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return nullptr;

    ListNode *pA = headA;
    ListNode *pB = headB;

    while (pA != pB)
    {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    return pA; // either intersection node or nullptr
}