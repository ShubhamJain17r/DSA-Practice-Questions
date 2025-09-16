#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=problem-list-v2&envId=two-pointers

int removeDuplicates(vector<int> &nums)
{
    int k = 1;
    int curr = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != curr)
        {
            nums[k++] = nums[i];
            curr = nums[i];
        }
    }
    return k;
}