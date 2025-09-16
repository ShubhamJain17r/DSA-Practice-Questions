#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/move-zeroes/description/?envType=problem-list-v2&envId=two-pointers

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int idx = 0;
    int k = 0;
    while (idx < n)
    {
        if (nums[idx] == 0)
        {
            idx++;
            continue;
        }
        swap(nums[idx++], nums[k++]);
    }
}