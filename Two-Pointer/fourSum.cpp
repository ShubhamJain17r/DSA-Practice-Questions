#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/4sum/description/?envType=problem-list-v2&envId=two-pointers

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> res;

    for (int i = 0; i < n - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n - 1; ++j)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            long long t = (long long)target - nums[i] - nums[j];
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                if ((long long)(nums[l] + nums[r]) == t)
                {
                    res.push_back((vector<int>){nums[i], nums[j], nums[l], nums[r]});
                    l++, r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if ((nums[l] + nums[r]) < t)
                    l++;
                else
                    r--;
            }
        }
    }
    return res;
}
