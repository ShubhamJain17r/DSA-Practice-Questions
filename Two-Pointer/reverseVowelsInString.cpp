#include <iostream>
#include <string>

using namespace std;

// https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=problem-list-v2&envId=two-pointers

bool isUpper(char c)
{
    return (c >= 'A' && c <= 'Z');
}
bool isLower(char c)
{
    return (c >= 'a' && c <= 'z');
}
bool isAlpha(char c)
{
    return (isUpper(c) || isLower(c));
}
bool isVowel(char c)
{
    if (!isAlpha(c))
        return false;
    if (isUpper(c))
        c = c + 32;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
string reverseVowels(string s)
{
    int n = s.length();

    int l = 0, r = n - 1;

    while (l < r)
    {
        while (l < r && !isVowel(s[l]))
            l++;
        while (l < r && !isVowel(s[r]))
            r--;
        swap(s[l++], s[r--]);
    }
    return s;
}
