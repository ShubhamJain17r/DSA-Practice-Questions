#include <iostream>
#include <string>

using namespace std;

// https://leetcode.com/problems/merge-strings-alternately/description/?envType=problem-list-v2&envId=two-pointers

string mergeAlternately(string word1, string word2)
{
    bool chance = true;
    string ans = "";
    int n = word1.length(), m = word2.length();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (chance)
        {
            ans.push_back(word1[i++]);
        }
        else
        {
            ans.push_back(word2[j++]);
        }
        chance = !chance;
    }
    while (i < n)
    {
        ans.push_back(word1[i++]);
    }
    while (j < m)
    {
        ans.push_back(word2[j++]);
    }
    return ans;
}