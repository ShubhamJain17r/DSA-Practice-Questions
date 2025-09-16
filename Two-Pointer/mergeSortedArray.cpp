#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/merge-sorted-array/description/?envType=problem-list-v2&envId=two-pointers

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (n == 0)
        return;
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}