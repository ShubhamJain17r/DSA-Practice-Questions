#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=problem-list-v2&envId=two-pointers

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (auto num : nums)
    {
        if ((i < 2) || (num > nums[i - 2]))
        {
            nums[i++] = num;
        }
    }
    return i;
}