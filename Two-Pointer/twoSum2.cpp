#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=problem-list-v2&envId=two-pointers

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();

    int l = 0, r = n - 1;

    while (l < r)
    {
        int sum = (nums[l] + nums[r]);

        cout << sum << endl;
        if (sum == target)
            return {l + 1, r + 1};
        else if ((nums[l] + nums[r]) < target)
            l++;
        else
            r--;
    }
    return {};
}