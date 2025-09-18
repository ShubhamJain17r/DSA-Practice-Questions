#include <iostream>
#include <string>

using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=two-pointers

string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    int start = 0, maxLen = 1;

    for (int i = 0; i < s.size(); i++)
    {
        // Odd length palindrome (center at i)
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }

        // Even length palindrome (center between i and i+1)
        l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    return s.substr(start, maxLen);
}