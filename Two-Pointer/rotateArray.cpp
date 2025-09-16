#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/rotate-array/description/?envType=problem-list-v2&envId=two-pointers

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    
    if (k == 0)
        return;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}