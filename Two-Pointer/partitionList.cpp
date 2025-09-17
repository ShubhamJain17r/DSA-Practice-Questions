#include <iostream>

using namespace std;

// https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=two-pointers

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode *temp = head;
    ListNode *Ls = nullptr;
    ListNode *Le = nullptr;
    ListNode *Rs = nullptr;
    ListNode *Re = nullptr;

    while (temp)
    {
        if (temp->val < x)
        {
            if (!Ls)
            {
                Ls = temp;
                Le = temp;
            }
            else
            {
                Le->next = temp;
                Le = temp;
            }
        }
        else
        {
            if (!Rs)
            {
                Rs = temp;
                Re = temp;
            }
            else
            {
                Re->next = temp;
                Re = temp;
            }
        }
        temp = temp->next;
    }
    if (Re)
        Re->next = nullptr;
    if (Le)
    {
        Le->next = Rs;
        return Ls;
    }
    return Rs;
}
