#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/reverse-string/description/?envType=problem-list-v2&envId=two-pointers

void reverseString(vector<char> &s)
{
    int n = s.size();
    int l = 0, r = n - 1;

    while (l < r)
    {
        s[l] ^= s[r];
        s[r] ^= s[l];
        s[l] ^= s[r];
        l++, r--;
    }
}