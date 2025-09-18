#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=two-pointers

// similar to detecting starting node of cycles in LL

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
