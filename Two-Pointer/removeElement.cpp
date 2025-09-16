#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/remove-element/description/?envType=problem-list-v2&envId=two-pointers

int removeElement(vector<int> &nums, int val)
{
    if (nums.size() == 0 || nums.size() == 1 && nums[0] == val)
        return 0;
    if (nums.size() == 1 && nums[0] != val)
        return 1;

    int k = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == val)
            continue;
        nums[k++] = nums[i];
    }
    return k;
}