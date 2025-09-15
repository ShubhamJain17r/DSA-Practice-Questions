#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// https://leetcode.com/problems/3sum-closest/description/?envType=problem-list-v2&envId=two-pointers

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i-1])continue;
        for (int l = i + 1, r = n - 1; l < r;)
        {
            int curr = nums[i] + nums[l] + nums[r];
            if (curr == target)
                return target;
            if (ans == INT_MAX)
                ans = curr;
            else if (abs(curr - target) <= abs(ans - target))
                ans = curr;
            if (curr < target)
                l++;
            else
                r--;
        }
    }
    return ans;
}
