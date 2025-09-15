#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/3sum/description/?envType=problem-list-v2&envId=two-pointers


vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    if (nums[0] > 0 || nums[n - 1] < 0)
        return (vector<vector<int>>){};
    if (nums[0] == 0 && nums[n - 1] == 0)
        return (vector<vector<int>>){{0, 0, 0}};

    vector<vector<int>> ans;
    for (int i = 0; i < (n - 2); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > 0)
            break;
        int target = -nums[i];
        for (int l = i + 1, r = nums.size() - 1; l < r;)
        {

            if ((nums[l] + nums[r]) == target)
            {
                vector<int> temp = {nums[i], nums[l], nums[r]};
                ans.push_back(temp);
                l++, r--;
                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
            else if ((nums[l] + nums[r]) > target)
                r--;
            else
                l++;
        }
    }
    return ans;
}

// hw -> try using set for optimization