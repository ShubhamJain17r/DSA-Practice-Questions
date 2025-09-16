#include <iostream>
#include <string>

using namespace std;

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=problem-list-v2&envId=two-pointers

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();
    if (m > n)
        return -1;
    for (int i = 0; i < n; ++i)
    {
        if (haystack[i] != needle[0])
            continue;
        int curr = i;
        int j = 0;
        while (curr < n && j < m && haystack[curr] == needle[j])
        {
            curr++;
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}