#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/next-permutation/description/?envType=problem-list-v2&envId=two-pointers

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
        --i;
    if (i == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int pivot = i;
    i = n - 1;
    while (i >= 0 && nums[i] <= nums[pivot])
        --i;
    swap(nums[i], nums[pivot]);

    reverse(nums.begin() + pivot + 1, nums.end());
}