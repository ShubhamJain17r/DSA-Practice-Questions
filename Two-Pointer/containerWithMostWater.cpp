#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/?envType=problem-list-v2&envId=two-pointers


int maxArea(vector<int> &height)
{
    int mostWater = 0;
    int l = 0, r = height.size() - 1;

    while (l < r)
    {
        int curr = (r - l) * min(height[l], height[r]);
        mostWater = max(mostWater, curr);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return mostWater;
}